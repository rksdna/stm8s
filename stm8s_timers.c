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
#include "stm8s_timers.h"
#include "stm8s_threads.h"

static struct stm8s_timer* head = 0;

static u8_t signal(struct stm8s_timer* timer)
{
    return timer->count;
}

void stm8s_sleep(u16_t ticks)
{
    struct stm8s_timer timer;
    stm8s_start_timer(&timer, ticks);
    stm8s_wait_timer(&timer);
    stm8s_stop_timer(&timer);
}

void stm8s_start_timer(struct stm8s_timer* timer, u16_t ticks)
{
    timer->ticks = 0;
    timer->count = 0;
    timer->range = ticks;
    timer->next = head;
    head = timer;
}

void stm8s_wait_timer(struct stm8s_timer* timer)
{
    stm8s_yield_thread((stm8s_signal_t)signal, (pointer_t)timer);
    timer->count = 0;
}

void stm8s_stop_timer(struct stm8s_timer* timer)
{
    if (head == timer)
    {
        head = timer->next;
    }
    else
    {
        struct stm8s_timer* previous = head;
        while (previous->next != timer)
            previous = previous->next;

        previous->next = timer->next;
    }
}

void stm8s_timer4_irq(void) __interrupt(23)
{
    struct stm8s_timer* timer = head;
    while (timer)
    {
        if (++timer->ticks >= timer->range)
        {
            timer->ticks = 0;
            timer->count++;
        }

        timer = timer->next;
    }

    TIM4->SR1 = 0x00;
}
