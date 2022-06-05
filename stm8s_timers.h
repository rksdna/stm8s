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

#ifndef STM8S_TIMERS_H
#define STM8S_TIMERS_H

#include "stm8s_types.h"

struct stm8s_timer
{
    u16_t ticks;
    u16_t range;
    u16_t count;
    struct stm8s_timer* next;
};

void stm8s_sleep(u16_t ticks);

void stm8s_start_timer(struct stm8s_timer* timer, u16_t ticks);
void stm8s_wait_timer(struct stm8s_timer* timer);
void stm8s_stop_timer(struct stm8s_timer* timer);

void stm8s_timer4_irq(void) __interrupt(23);

#endif
