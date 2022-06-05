/*
 * stm8s - STM8 SDCC cooperative multitasking operating system
 * Copyright (c) 2022 rksdna
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "stm8s_registers.h"
#include "stm8s_threads.h"
#include "stm8s_timers.h"

static u8_t flag = 0x00;
static u16_t sample = 0;

static void handler1(u16_t count)
{
    while (count--)
    {
        GPIOB->ODR &= ~(1 << 4);
        stm8s_sleep(50);
        GPIOB->ODR |= (1 << 4);
        stm8s_sleep(250);
    }

    flag = 0x01;
}

static void handler2(u16_t count)
{
    struct stm8s_timer timer;

    // wait thread1
    stm8s_wait_memory(&flag, 0x01, 0x01);

    stm8s_start_timer(&timer, 100);
    while (count--)
    {
        GPIOB->ODR ^= (1 << 5);
        stm8s_wait_timer(&timer);
    }

    stm8s_stop_timer(&timer);
}

static void handler3(u16_t* sample)
{
    GPIOC->ODR &= ~(1 << 3);

    stm8s_sleep(50);

    // startup
    ADC1->CSR = 0;
    ADC1->CR2 = ADC1_CR2_ALIGN;
    ADC1->CR1 = ADC1_CR1_ADON;

    // start conversion
    ADC1->CR1 |= ADC1_CR1_ADON;

    // wait
    stm8s_wait_memory(&ADC1->CSR, ADC1_CSR_EOC, ADC1_CSR_EOC);
    ADC1->CSR &= ~ADC1_CSR_EOC;

    // read data
    *sample = ADC1->DRL;
    *sample |= (ADC1->DRH << 8);

    GPIOC->ODR |= (1 << 3);

    // early exit
    stm8s_detach_thread();

    // unreachable code
    while (1)
        continue;
}

void main(void)
{
    struct stm8s_thread thread1;
    struct stm8s_thread thread2;
    struct stm8s_thread thread3;

    u8_t stack1[64];
    u8_t stack2[64];
    u8_t stack3[64];

    CLK->CKDIVR = 0x00;

    GPIOC->DDR = (1 << 3);
    GPIOC->CR1 = (1 << 3);

    GPIOB->DDR = (1 << 5) | (1 << 4);
    GPIOB->CR1 = (1 << 5) | (1 << 4);

    TIM4->PSCR = 7;
    TIM4->ARR = 125 - 1;
    TIM4->IER = TIM4_IER_UIE;
    TIM4->CR1 = TIM4_CR1_CEN;

    stm8s_attach_thread(&thread1, (stm8s_handler_t)handler1, 10, stack1, sizeof(stack1));
    stm8s_attach_thread(&thread2, (stm8s_handler_t)handler2, 15, stack2, sizeof(stack2));
    stm8s_attach_thread(&thread3, (stm8s_handler_t)handler3, (pointer_t)&sample, stack3, sizeof(stack3));

    // execute threads
    stm8s_threads_run();

    // all threads fininshed
    stm8s_reboot();
}

