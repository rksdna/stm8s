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

#ifndef STM8S_THREADS_H
#define STM8S_THREADS_H

#include "stm8s_types.h"

typedef void (*stm8s_handler_t)(pointer_t data);
typedef u8_t (*stm8s_signal_t)(pointer_t data);

struct stm8s_thread
{
    pointer_t stack;
    pointer_t data;
    stm8s_signal_t signal;
    struct stm8s_thread* next;
};

void stm8s_reboot(void);

void stm8s_attach_thread(struct stm8s_thread* thread, stm8s_handler_t handler, pointer_t data, u8_t* stack, size_t size);
void stm8s_threads_run(void);

void stm8s_yield_thread(stm8s_signal_t signal, pointer_t data);
void stm8s_detach_thread(void);

void stm8s_wait_memory(volatile u8_t* memory, u8_t mask, u8_t data);

void stm8s_trap_irq(void) __trap __naked;

#endif
