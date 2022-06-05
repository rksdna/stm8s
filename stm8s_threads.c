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

struct stm8s_bind
{
    volatile u8_t* memory;
    u8_t mask;
    u8_t data;
};

static struct stm8s_thread* head = 0;

static u8_t signal(struct stm8s_bind* bind)
{
    return (*bind->memory & bind->mask) == bind->data;
}

static void helper(struct stm8s_thread* thread)
{
    struct stm8s_thread* tail = head;
    while (tail->next != head)
        tail = tail->next;

    tail->next = thread;
}

void stm8s_reboot(void)
{
    WWDG->CR = WWDG_CR_WDGA;
}

void stm8s_attach_thread(struct stm8s_thread* thread, stm8s_handler_t handler, pointer_t data, u8_t* stack, size_t size)
{
    stack += size - 1;
    *stack-- = (u8_t)(data); // datal
    *stack-- = (u8_t)(data >> 8); // datah
    *stack-- = (u8_t)((pointer_t)stm8s_detach_thread); // pcl
    *stack-- = (u8_t)((pointer_t)stm8s_detach_thread >> 8); // pch

    *stack-- = (u8_t)((pointer_t)handler); // pcl
    *stack-- = (u8_t)((pointer_t)handler >> 8); // pch
    *stack-- = 0x00; // pce
    *stack-- = 0x00; // yl
    *stack-- = 0x00; // yh
    *stack-- = 0x00; // xl
    *stack-- = 0x00; // xh
    *stack-- = 0x00; // a
    *stack-- = 0x50; // cc

    thread->stack = (pointer_t)stack;
    thread->data = data;
    thread->signal = 0;

    if (head == 0)
        head = thread;
    else
        helper(thread);

    thread->next = head;
}

void stm8s_threads_run(void)
{
    __asm__ ("rim");
    while (head)
    {
        if (head->signal == 0 || head->signal(head->data))
            __asm__ ("trap");

        head = head->next;
    }
}

void stm8s_yield_thread(stm8s_signal_t signal, pointer_t data)
{
    head->signal = signal;
    head->data = data;
    __asm__ ("trap");
}

void stm8s_detach_thread(void)
{
    helper(head->next == head ? 0 : head->next);
    __asm__ ("trap");
}

void stm8s_wait_memory(volatile u8_t* memory, u8_t mask, u8_t data)
{
    struct stm8s_bind bind = {memory, mask, data};
    stm8s_yield_thread((stm8s_signal_t)signal, (pointer_t)&bind);
}

void stm8s_trap_irq(void) __trap __naked
{
    __asm__ ("ldw x, [_head]");
    __asm__ ("ldw y, sp");
    __asm__ ("ldw sp, x");
    __asm__ ("exgw x, y");
    __asm__ ("ldw [_head], x");
    __asm__ ("iret");
}

