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

#ifndef STM8S_REGISTERS_H
#define STM8S_REGISTERS_H

#include "stm8s_types.h"

struct stm8s_gpio
{
    volatile u8_t ODR;
    volatile u8_t IDR;
    volatile u8_t DDR;
    volatile u8_t CR1;
    volatile u8_t CR2;
};

#define GPIOA ((struct stm8s_gpio*)0x5000)
#define GPIOB ((struct stm8s_gpio*)0x5005)
#define GPIOC ((struct stm8s_gpio*)0x500A)
#define GPIOD ((struct stm8s_gpio*)0x500F)
#define GPIOE ((struct stm8s_gpio*)0x5014)
#define GPIOF ((struct stm8s_gpio*)0x5019)
#define GPIOG ((struct stm8s_gpio*)0x501E)
#define GPIOH ((struct stm8s_gpio*)0x5023)
#define GPIOI ((struct stm8s_gpio*)0x5028)

struct stm8s_adc1
{
    volatile u8_t DB0RH;
    volatile u8_t DB0RL;
    volatile u8_t DB1RH;
    volatile u8_t DB1RL;
    volatile u8_t DB2RH;
    volatile u8_t DB2RL;
    volatile u8_t DB3RH;
    volatile u8_t DB3RL;
    volatile u8_t DB4RH;
    volatile u8_t DB4RL;
    volatile u8_t DB5RH;
    volatile u8_t DB5RL;
    volatile u8_t DB6RH;
    volatile u8_t DB6RL;
    volatile u8_t DB7RH;
    volatile u8_t DB7RL;
    volatile u8_t DB8RH;
    volatile u8_t DB8RL;
    volatile u8_t DB9RH;
    volatile u8_t DB9RL;
    u8_t RESERVED[12];
    volatile u8_t CSR;
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t CR3;
    volatile u8_t DRH;
    volatile u8_t DRL;
    volatile u8_t TDRH;
    volatile u8_t TDRL;
    volatile u8_t HTRH;
    volatile u8_t HTRL;
    volatile u8_t LTRH;
    volatile u8_t LTRL;
    volatile u8_t AWSRH;
    volatile u8_t AWSRL;
    volatile u8_t AWCRH;
    volatile u8_t AWCRL;
};

#define ADC1 ((struct stm8s_adc1*)0x53E0)

#define ADC1_CSR_EOC ((u8_t)0x80)
#define ADC1_CSR_AWD ((u8_t)0x40)
#define ADC1_CSR_EOCIE ((u8_t)0x20)
#define ADC1_CSR_AWDIE ((u8_t)0x10)
#define ADC1_CSR_CH ((u8_t)0x0F)

#define ADC1_CR1_SPSEL ((u8_t)0x70)
#define ADC1_CR1_CONT ((u8_t)0x02)
#define ADC1_CR1_ADON ((u8_t)0x01)

#define ADC1_CR2_EXTTRIG ((u8_t)0x40)
#define ADC1_CR2_EXTSEL ((u8_t)0x30)
#define ADC1_CR2_ALIGN ((u8_t)0x08)
#define ADC1_CR2_SCAN ((u8_t)0x02)
#define ADC1_CR3_DBUF ((u8_t)0x80)
#define ADC1_CR3_OVR ((u8_t)0x40)

struct stm8s_adc2
{
    volatile u8_t CSR;
    volatile u8_t CR1;
    volatile u8_t CR2;
    u8_t RESERVED;
    volatile u8_t DRH;
    volatile u8_t DRL;
    volatile u8_t TDRH;
    volatile u8_t TDRL;
};

#define ADC2 ((struct stm8s_adc2*)0x5400)

#define ADC2_CSR_EOC ((u8_t)0x80)
#define ADC2_CSR_EOCIE ((u8_t)0x20)
#define ADC2_CSR_CH ((u8_t)0x0F)

#define ADC2_CR1_SPSEL ((u8_t)0x70)
#define ADC2_CR1_CONT ((u8_t)0x02)
#define ADC2_CR1_ADON ((u8_t)0x01)
#define ADC2_CR2_EXTTRIG ((u8_t)0x40)
#define ADC2_CR2_EXTSEL ((u8_t)0x30)
#define ADC2_CR2_ALIGN ((u8_t)0x08)

struct stm8s_awu
{
    volatile u8_t CSR;
    volatile u8_t APR;
    volatile u8_t TBR;
};

#define AWU ((struct stm8s_awu*)0x50F0)


#define AWU_CSR_AWUF ((u8_t)0x20)
#define AWU_CSR_AWUEN ((u8_t)0x10)
#define AWU_CSR_MSR ((u8_t)0x01)

#define AWU_APR_APR ((u8_t)0x3F)

#define AWU_TBR_AWUTB ((u8_t)0x0F)

struct stm8s_beep
{
    volatile u8_t CSR;
};

#define BEEP ((struct stm8s_beep*)0x50F3)

#define BEEP_CSR_BEEPSEL ((u8_t)0xC0)
#define BEEP_CSR_BEEPEN ((u8_t)0x20)
#define BEEP_CSR_BEEPDIV ((u8_t)0x1F)

struct stm8s_clk
{
    volatile u8_t ICKR;
    volatile u8_t ECKR;
    u8_t RESERVED;
    volatile u8_t CMSR;
    volatile u8_t SWR;
    volatile u8_t SWCR;
    volatile u8_t CKDIVR;
    volatile u8_t PCKENR1;
    volatile u8_t CSSR;
    volatile u8_t CCOR;
    volatile u8_t PCKENR2;
    u8_t RESERVED1;
    volatile u8_t HSITRIMR;
    volatile u8_t SWIMCCR;
};

#define CLK ((struct stm8s_clk*)0x50C0)

#define CLK_ICKR_SWUAH ((u8_t)0x20)
#define CLK_ICKR_LSIRDY ((u8_t)0x10)
#define CLK_ICKR_LSIEN ((u8_t)0x08)
#define CLK_ICKR_FHWU ((u8_t)0x04)
#define CLK_ICKR_HSIRDY ((u8_t)0x02)
#define CLK_ICKR_HSIEN ((u8_t)0x01)

#define CLK_ECKR_HSERDY ((u8_t)0x02)
#define CLK_ECKR_HSEEN ((u8_t)0x01)

#define CLK_CMSR_CKM ((u8_t)0xFF)

#define CLK_SWR_SWI ((u8_t)0xFF)

#define CLK_SWCR_SWIF ((u8_t)0x08)
#define CLK_SWCR_SWIEN ((u8_t)0x04)
#define CLK_SWCR_SWEN ((u8_t)0x02)
#define CLK_SWCR_SWBSY ((u8_t)0x01)

#define CLK_CKDIVR_HSIDIV ((u8_t)0x18)
#define CLK_CKDIVR_CPUDIV ((u8_t)0x07)

#define CLK_PCKENR1_TIM1 ((u8_t)0x80)
#define CLK_PCKENR1_TIM3 ((u8_t)0x40)
#define CLK_PCKENR1_TIM2 ((u8_t)0x20)
#define CLK_PCKENR1_TIM5 ((u8_t)0x20)
#define CLK_PCKENR1_TIM4 ((u8_t)0x10)
#define CLK_PCKENR1_TIM6 ((u8_t)0x10)
#define CLK_PCKENR1_UART3 ((u8_t)0x08)
#define CLK_PCKENR1_UART2 ((u8_t)0x08)
#define CLK_PCKENR1_UART1 ((u8_t)0x04)
#define CLK_PCKENR1_SPI ((u8_t)0x02)

#define CLK_PCKENR1_I2C ((u8_t)0x01)
#define CLK_PCKENR2_CAN ((u8_t)0x80)
#define CLK_PCKENR2_ADC ((u8_t)0x08)
#define CLK_PCKENR2_AWU ((u8_t)0x04)

#define CLK_CSSR_CSSD ((u8_t)0x08)
#define CLK_CSSR_CSSDIE ((u8_t)0x04)
#define CLK_CSSR_AUX ((u8_t)0x02)
#define CLK_CSSR_CSSEN ((u8_t)0x01)

#define CLK_CCOR_CCOBSY ((u8_t)0x40)
#define CLK_CCOR_CCORDY ((u8_t)0x20)
#define CLK_CCOR_CCOSEL ((u8_t)0x1E)
#define CLK_CCOR_CCOEN ((u8_t)0x01)

#define CLK_HSITRIMR_HSITRIM ((u8_t)0x07)
#define CLK_SWIMCCR_SWIMDIV ((u8_t)0x01)

struct stm8s_tim1
{
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t SMCR;
    volatile u8_t ETR;
    volatile u8_t IER;
    volatile u8_t SR1;
    volatile u8_t SR2;
    volatile u8_t EGR;
    volatile u8_t CCMR1;
    volatile u8_t CCMR2;
    volatile u8_t CCMR3;
    volatile u8_t CCMR4;
    volatile u8_t CCER1;
    volatile u8_t CCER2;
    volatile u8_t CNTRH;
    volatile u8_t CNTRL;
    volatile u8_t PSCRH;
    volatile u8_t PSCRL;
    volatile u8_t ARRH;
    volatile u8_t ARRL;
    volatile u8_t RCR;
    volatile u8_t CCR1H;
    volatile u8_t CCR1L;
    volatile u8_t CCR2H;
    volatile u8_t CCR2L;
    volatile u8_t CCR3H;
    volatile u8_t CCR3L;
    volatile u8_t CCR4H;
    volatile u8_t CCR4L;
    volatile u8_t BKR;
    volatile u8_t DTR;
    volatile u8_t OISR;
};

#define TIM1 ((struct stm8s_tim1*) 0x5250)

#define TIM1_CR1_ARPE ((u8_t)0x80)
#define TIM1_CR1_CMS ((u8_t)0x60)
#define TIM1_CR1_DIR ((u8_t)0x10)
#define TIM1_CR1_OPM ((u8_t)0x08)
#define TIM1_CR1_URS ((u8_t)0x04)
#define TIM1_CR1_UDIS ((u8_t)0x02)
#define TIM1_CR1_CEN ((u8_t)0x01)

#define TIM1_CR2_TI1S ((u8_t)0x80)
#define TIM1_CR2_MMS ((u8_t)0x70)
#define TIM1_CR2_COMS ((u8_t)0x04)
#define TIM1_CR2_CCPC ((u8_t)0x01)

#define TIM1_SMCR_MSM ((u8_t)0x80)
#define TIM1_SMCR_TS ((u8_t)0x70)
#define TIM1_SMCR_SMS ((u8_t)0x07)

#define TIM1_ETR_ETP ((u8_t)0x80)
#define TIM1_ETR_ECE ((u8_t)0x40)
#define TIM1_ETR_ETPS ((u8_t)0x30)
#define TIM1_ETR_ETF ((u8_t)0x0F)

#define TIM1_IER_BIE ((u8_t)0x80)
#define TIM1_IER_TIE ((u8_t)0x40)
#define TIM1_IER_COMIE ((u8_t)0x20)
#define TIM1_IER_CC4IE ((u8_t)0x10)
#define TIM1_IER_CC3IE ((u8_t)0x08)
#define TIM1_IER_CC2IE ((u8_t)0x04)
#define TIM1_IER_CC1IE ((u8_t)0x02)
#define TIM1_IER_UIE ((u8_t)0x01)

#define TIM1_SR1_BIF ((u8_t)0x80)
#define TIM1_SR1_TIF ((u8_t)0x40)
#define TIM1_SR1_COMIF ((u8_t)0x20)
#define TIM1_SR1_CC4IF ((u8_t)0x10)
#define TIM1_SR1_CC3IF ((u8_t)0x08)
#define TIM1_SR1_CC2IF ((u8_t)0x04)
#define TIM1_SR1_CC1IF ((u8_t)0x02)
#define TIM1_SR1_UIF ((u8_t)0x01)

#define TIM1_SR2_CC4OF ((u8_t)0x10)
#define TIM1_SR2_CC3OF ((u8_t)0x08)
#define TIM1_SR2_CC2OF ((u8_t)0x04)
#define TIM1_SR2_CC1OF ((u8_t)0x02)

#define TIM1_EGR_BG ((u8_t)0x80)
#define TIM1_EGR_TG ((u8_t)0x40)
#define TIM1_EGR_COMG ((u8_t)0x20)
#define TIM1_EGR_CC4G ((u8_t)0x10)
#define TIM1_EGR_CC3G ((u8_t)0x08)
#define TIM1_EGR_CC2G ((u8_t)0x04)
#define TIM1_EGR_CC1G ((u8_t)0x02)
#define TIM1_EGR_UG ((u8_t)0x01)

#define TIM1_CCMR_ICxPSC ((u8_t)0x0C)
#define TIM1_CCMR_ICxF ((u8_t)0xF0)
#define TIM1_CCMR_OCM ((u8_t)0x70)
#define TIM1_CCMR_OCxPE ((u8_t)0x08)
#define TIM1_CCMR_OCxFE ((u8_t)0x04)
#define TIM1_CCMR_CCxS ((u8_t)0x03)

#define CCMR_TIxDirect_Set ((u8_t)0x01)

#define TIM1_CCER1_CC2NP ((u8_t)0x80)
#define TIM1_CCER1_CC2NE ((u8_t)0x40)
#define TIM1_CCER1_CC2P ((u8_t)0x20)
#define TIM1_CCER1_CC2E ((u8_t)0x10)
#define TIM1_CCER1_CC1NP ((u8_t)0x08)
#define TIM1_CCER1_CC1NE ((u8_t)0x04)
#define TIM1_CCER1_CC1P ((u8_t)0x02)
#define TIM1_CCER1_CC1E ((u8_t)0x01)

#define TIM1_CCER2_CC4P ((u8_t)0x20)
#define TIM1_CCER2_CC4E ((u8_t)0x10)
#define TIM1_CCER2_CC3NP ((u8_t)0x08)
#define TIM1_CCER2_CC3NE ((u8_t)0x04)
#define TIM1_CCER2_CC3P ((u8_t)0x02)
#define TIM1_CCER2_CC3E ((u8_t)0x01)

#define TIM1_CNTRH_CNT ((u8_t)0xFF)
#define TIM1_CNTRL_CNT ((u8_t)0xFF)

#define TIM1_PSCH_PSC ((u8_t)0xFF)

#define TIM1_PSCL_PSC ((u8_t)0xFF)

#define TIM1_ARRH_ARR ((u8_t)0xFF)

#define TIM1_ARRL_ARR ((u8_t)0xFF)

#define TIM1_RCR_REP ((u8_t)0xFF)

#define TIM1_CCR1H_CCR1 ((u8_t)0xFF)

#define TIM1_CCR1L_CCR1 ((u8_t)0xFF)

#define TIM1_CCR2H_CCR2 ((u8_t)0xFF)

#define TIM1_CCR2L_CCR2 ((u8_t)0xFF)

#define TIM1_CCR3H_CCR3 ((u8_t)0xFF)

#define TIM1_CCR3L_CCR3 ((u8_t)0xFF)

#define TIM1_CCR4H_CCR4 ((u8_t)0xFF)

#define TIM1_CCR4L_CCR4 ((u8_t)0xFF)

#define TIM1_BKR_MOE ((u8_t)0x80)
#define TIM1_BKR_AOE ((u8_t)0x40)
#define TIM1_BKR_BKP ((u8_t)0x20)
#define TIM1_BKR_BKE ((u8_t)0x10)
#define TIM1_BKR_OSSR ((u8_t)0x08)
#define TIM1_BKR_OSSI ((u8_t)0x04)
#define TIM1_BKR_LOCK ((u8_t)0x03)

#define TIM1_DTR_DTG ((u8_t)0xFF)

#define TIM1_OISR_OIS4 ((u8_t)0x40)
#define TIM1_OISR_OIS3N ((u8_t)0x20)
#define TIM1_OISR_OIS3 ((u8_t)0x10)
#define TIM1_OISR_OIS2N ((u8_t)0x08)
#define TIM1_OISR_OIS2 ((u8_t)0x04)
#define TIM1_OISR_OIS1N ((u8_t)0x02)
#define TIM1_OISR_OIS1 ((u8_t)0x01)

struct stm8s_tim2
{
    volatile u8_t CR1;
#if defined(STM8S103) || defined(STM8S003)
    u8_t RESERVED1;
    u8_t RESERVED2;
#endif
    volatile u8_t IER;
    volatile u8_t SR1;
    volatile u8_t SR2;
    volatile u8_t EGR;
    volatile u8_t CCMR1;
    volatile u8_t CCMR2;
    volatile u8_t CCMR3;
    volatile u8_t CCER1;
    volatile u8_t CCER2;
    volatile u8_t CNTRH;
    volatile u8_t CNTRL;
    volatile u8_t PSCR;
    volatile u8_t ARRH;
    volatile u8_t ARRL;
    volatile u8_t CCR1H;
    volatile u8_t CCR1L;
    volatile u8_t CCR2H;
    volatile u8_t CCR2L;
    volatile u8_t CCR3H;
    volatile u8_t CCR3L;
};

#define TIM2 ((struct stm8s_tim2*) 0x5300)

#define TIM2_CR1_ARPE ((u8_t)0x80)
#define TIM2_CR1_OPM ((u8_t)0x08)
#define TIM2_CR1_URS ((u8_t)0x04)
#define TIM2_CR1_UDIS ((u8_t)0x02)
#define TIM2_CR1_CEN ((u8_t)0x01)

#define TIM2_IER_CC3IE ((u8_t)0x08)
#define TIM2_IER_CC2IE ((u8_t)0x04)
#define TIM2_IER_CC1IE ((u8_t)0x02)
#define TIM2_IER_UIE ((u8_t)0x01)

#define TIM2_SR1_CC3IF ((u8_t)0x08)
#define TIM2_SR1_CC2IF ((u8_t)0x04)
#define TIM2_SR1_CC1IF ((u8_t)0x02)
#define TIM2_SR1_UIF ((u8_t)0x01)

#define TIM2_SR2_CC3OF ((u8_t)0x08)
#define TIM2_SR2_CC2OF ((u8_t)0x04)
#define TIM2_SR2_CC1OF ((u8_t)0x02)

#define TIM2_EGR_CC3G ((u8_t)0x08)
#define TIM2_EGR_CC2G ((u8_t)0x04)
#define TIM2_EGR_CC1G ((u8_t)0x02)
#define TIM2_EGR_UG ((u8_t)0x01)

#define TIM2_CCMR_ICxPSC ((u8_t)0x0C)
#define TIM2_CCMR_ICxF ((u8_t)0xF0)
#define TIM2_CCMR_OCM ((u8_t)0x70)
#define TIM2_CCMR_OCxPE ((u8_t)0x08)
#define TIM2_CCMR_CCxS ((u8_t)0x03)

#define TIM2_CCER1_CC2P ((u8_t)0x20)
#define TIM2_CCER1_CC2E ((u8_t)0x10)
#define TIM2_CCER1_CC1P ((u8_t)0x02)
#define TIM2_CCER1_CC1E ((u8_t)0x01)

#define TIM2_CCER2_CC3P ((u8_t)0x02)
#define TIM2_CCER2_CC3E ((u8_t)0x01)

#define TIM2_CNTRH_CNT ((u8_t)0xFF)
#define TIM2_CNTRL_CNT ((u8_t)0xFF)

#define TIM2_PSCR_PSC ((u8_t)0xFF)

#define TIM2_ARRH_ARR ((u8_t)0xFF)
#define TIM2_ARRL_ARR ((u8_t)0xFF)

#define TIM2_CCR1H_CCR1 ((u8_t)0xFF)

#define TIM2_CCR1L_CCR1 ((u8_t)0xFF)

#define TIM2_CCR2H_CCR2 ((u8_t)0xFF)

#define TIM2_CCR2L_CCR2 ((u8_t)0xFF)

#define TIM2_CCR3H_CCR3 ((u8_t)0xFF)

#define TIM2_CCR3L_CCR3 ((u8_t)0xFF)

struct stm8s_tim3
{
    volatile u8_t CR1;
    volatile u8_t IER;
    volatile u8_t SR1;
    volatile u8_t SR2;
    volatile u8_t EGR;
    volatile u8_t CCMR1;
    volatile u8_t CCMR2;
    volatile u8_t CCER1;
    volatile u8_t CNTRH;
    volatile u8_t CNTRL;
    volatile u8_t PSCR;
    volatile u8_t ARRH;
    volatile u8_t ARRL;
    volatile u8_t CCR1H;
    volatile u8_t CCR1L;
    volatile u8_t CCR2H;
    volatile u8_t CCR2L;
};

#define TIM3 ((struct stm8s_tim3*) 0x5320)

#define TIM3_CR1_ARPE ((u8_t)0x80)
#define TIM3_CR1_OPM ((u8_t)0x08)
#define TIM3_CR1_URS ((u8_t)0x04)
#define TIM3_CR1_UDIS ((u8_t)0x02)
#define TIM3_CR1_CEN ((u8_t)0x01)

#define TIM3_IER_CC2IE ((u8_t)0x04)
#define TIM3_IER_CC1IE ((u8_t)0x02)
#define TIM3_IER_UIE ((u8_t)0x01)

#define TIM3_SR1_CC2IF ((u8_t)0x04)
#define TIM3_SR1_CC1IF ((u8_t)0x02)
#define TIM3_SR1_UIF ((u8_t)0x01)

#define TIM3_SR2_CC2OF ((u8_t)0x04)
#define TIM3_SR2_CC1OF ((u8_t)0x02)

#define TIM3_EGR_CC2G ((u8_t)0x04)
#define TIM3_EGR_CC1G ((u8_t)0x02)
#define TIM3_EGR_UG ((u8_t)0x01)

#define TIM3_CCMR_ICxPSC ((u8_t)0x0C)
#define TIM3_CCMR_ICxF ((u8_t)0xF0)
#define TIM3_CCMR_OCM ((u8_t)0x70)
#define TIM3_CCMR_OCxPE ((u8_t)0x08)
#define TIM3_CCMR_CCxS ((u8_t)0x03)

#define TIM3_CCER1_CC2P ((u8_t)0x20)
#define TIM3_CCER1_CC2E ((u8_t)0x10)
#define TIM3_CCER1_CC1P ((u8_t)0x02)
#define TIM3_CCER1_CC1E ((u8_t)0x01)

#define TIM3_CNTRH_CNT ((u8_t)0xFF)

#define TIM3_CNTRL_CNT ((u8_t)0xFF)

#define TIM3_PSCR_PSC ((u8_t)0xFF)

#define TIM3_ARRH_ARR ((u8_t)0xFF)

#define TIM3_ARRL_ARR ((u8_t)0xFF)

#define TIM3_CCR1H_CCR1 ((u8_t)0xFF)

#define TIM3_CCR1L_CCR1 ((u8_t)0xFF)

#define TIM3_CCR2H_CCR2 ((u8_t)0xFF)

#define TIM3_CCR2L_CCR2 ((u8_t)0xFF)

struct stm8s_tim4
{
    volatile u8_t CR1;
#if defined(STM8S103) || defined(STM8S003)
    u8_t RESERVED1;
    u8_t RESERVED2;
#endif
    volatile u8_t IER;
    volatile u8_t SR1;
    volatile u8_t EGR;
    volatile u8_t CNTR;
    volatile u8_t PSCR;
    volatile u8_t ARR;
};

#define TIM4 ((struct stm8s_tim4*) 0x5340)

#define TIM4_CR1_ARPE ((u8_t)0x80)
#define TIM4_CR1_OPM ((u8_t)0x08)
#define TIM4_CR1_URS ((u8_t)0x04)
#define TIM4_CR1_UDIS ((u8_t)0x02)
#define TIM4_CR1_CEN ((u8_t)0x01)

#define TIM4_IER_UIE ((u8_t)0x01)

#define TIM4_SR1_UIF ((u8_t)0x01)

#define TIM4_EGR_UG ((u8_t)0x01)

#define TIM4_CNTR_CNT ((u8_t)0xFF)

#define TIM4_PSCR_PSC ((u8_t)0x07)

#define TIM4_ARR_ARR ((u8_t)0xFF)

struct stm8s_tim5
{
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t SMCR;
    volatile u8_t IER;
    volatile u8_t SR1;
    volatile u8_t SR2;
    volatile u8_t EGR;
    volatile u8_t CCMR1;
    volatile u8_t CCMR2;
    volatile u8_t CCMR3;
    volatile u8_t CCER1;
    volatile u8_t CCER2;
    volatile u8_t CNTRH;
    volatile u8_t CNTRL;
    volatile u8_t PSCR;
    volatile u8_t ARRH;
    volatile u8_t ARRL;
    volatile u8_t CCR1H;
    volatile u8_t CCR1L;
    volatile u8_t CCR2H;
    volatile u8_t CCR2L;
    volatile u8_t CCR3H;
    volatile u8_t CCR3L;
};

#define TIM5 ((struct stm8s_tim5*) 0x5300)

#define TIM5_CR1_ARPE ((u8_t)0x80)
#define TIM5_CR1_OPM ((u8_t)0x08)
#define TIM5_CR1_URS ((u8_t)0x04)
#define TIM5_CR1_UDIS ((u8_t)0x02)
#define TIM5_CR1_CEN ((u8_t)0x01)

#define TIM5_CR2_TI1S ((u8_t)0x80)
#define TIM5_CR2_MMS ((u8_t)0x70)

#define TIM5_SMCR_MSM ((u8_t)0x80)
#define TIM5_SMCR_TS ((u8_t)0x70)
#define TIM5_SMCR_SMS ((u8_t)0x07)

#define TIM5_IER_TIE ((u8_t)0x40)
#define TIM5_IER_CC3IE ((u8_t)0x08)
#define TIM5_IER_CC2IE ((u8_t)0x04)
#define TIM5_IER_CC1IE ((u8_t)0x02)
#define TIM5_IER_UIE ((u8_t)0x01)

#define TIM5_SR1_TIF ((u8_t)0x40)
#define TIM5_SR1_CC3IF ((u8_t)0x08)
#define TIM5_SR1_CC2IF ((u8_t)0x04)
#define TIM5_SR1_CC1IF ((u8_t)0x02)
#define TIM5_SR1_UIF ((u8_t)0x01)

#define TIM5_SR2_CC3OF ((u8_t)0x08)
#define TIM5_SR2_CC2OF ((u8_t)0x04)
#define TIM5_SR2_CC1OF ((u8_t)0x02)

#define TIM5_EGR_TG ((u8_t)0x40)
#define TIM5_EGR_CC3G ((u8_t)0x08)
#define TIM5_EGR_CC2G ((u8_t)0x04)
#define TIM5_EGR_CC1G ((u8_t)0x02)
#define TIM5_EGR_UG ((u8_t)0x01)

#define TIM5_CCMR_ICxPSC ((u8_t)0x0C)
#define TIM5_CCMR_ICxF ((u8_t)0xF0)
#define TIM5_CCMR_OCM ((u8_t)0x70)
#define TIM5_CCMR_OCxPE ((u8_t)0x08)
#define TIM5_CCMR_CCxS ((u8_t)0x03)
#define TIM5_CCMR_TIxDirect_Set ((u8_t)0x01)

#define TIM5_CCER1_CC2P ((u8_t)0x20)
#define TIM5_CCER1_CC2E ((u8_t)0x10)
#define TIM5_CCER1_CC1P ((u8_t)0x02)
#define TIM5_CCER1_CC1E ((u8_t)0x01)

#define TIM5_CCER2_CC3P ((u8_t)0x02)
#define TIM5_CCER2_CC3E ((u8_t)0x01)

#define TIM5_CNTRH_CNT ((u8_t)0xFF)

#define TIM5_CNTRL_CNT ((u8_t)0xFF)

#define TIM5_PSCR_PSC ((u8_t)0xFF)

#define TIM5_ARRH_ARR ((u8_t)0xFF)

#define TIM5_ARRL_ARR ((u8_t)0xFF)

#define TIM5_CCR1H_CCR1 ((u8_t)0xFF)

#define TIM5_CCR1L_CCR1 ((u8_t)0xFF)

#define TIM5_CCR2H_CCR2 ((u8_t)0xFF)

#define TIM5_CCR2L_CCR2 ((u8_t)0xFF)

#define TIM5_CCR3H_CCR3 ((u8_t)0xFF)

#define TIM5_CCR3L_CCR3 ((u8_t)0xFF)

struct stm8s_tim6
{
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t SMCR;
    volatile u8_t IER;
    volatile u8_t SR1;
    volatile u8_t EGR;
    volatile u8_t CNTR;
    volatile u8_t PSCR;
    volatile u8_t ARR;
};

#define TIM6 ((struct stm8s_tim6*) 0x5340)

#define TIM6_CR1_ARPE ((u8_t)0x80)
#define TIM6_CR1_OPM ((u8_t)0x08)
#define TIM6_CR1_URS ((u8_t)0x04)
#define TIM6_CR1_UDIS ((u8_t)0x02)
#define TIM6_CR1_CEN ((u8_t)0x01)

#define TIM6_CR2_MMS ((u8_t)0x70)

#define TIM6_SMCR_MSM ((u8_t)0x80)
#define TIM6_SMCR_TS ((u8_t)0x70)
#define TIM6_SMCR_SMS ((u8_t)0x07)

#define TIM6_IER_TIE ((u8_t)0x40)
#define TIM6_IER_UIE ((u8_t)0x01)

#define TIM6_SR1_TIF ((u8_t)0x40)
#define TIM6_SR1_UIF ((u8_t)0x01)

#define TIM6_EGR_TG ((u8_t)0x40)
#define TIM6_EGR_UG ((u8_t)0x01)

#define TIM6_CNTR_CNT ((u8_t)0xFF)

#define TIM6_PSCR_PSC ((u8_t)0x07)

#define TIM6_ARR_ARR ((u8_t)0xFF)

struct stm8s_i2c
{
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t FREQR;
    volatile u8_t OARL;
    volatile u8_t OARH;
    u8_t RESERVED1;
    volatile u8_t DR;
    volatile u8_t SR1;
    volatile u8_t SR2;
    volatile u8_t SR3;
    volatile u8_t ITR;
    volatile u8_t CCRL;
    volatile u8_t CCRH;
    volatile u8_t TRISER;
    u8_t RESERVED2;
};

#define I2C ((struct stm8s_i2c*) 0x5210)

#define I2C_CR1_NOSTRETCH ((u8_t)0x80)
#define I2C_CR1_ENGC ((u8_t)0x40)
#define I2C_CR1_PE ((u8_t)0x01)

#define I2C_CR2_SWRST ((u8_t)0x80)
#define I2C_CR2_POS ((u8_t)0x08)
#define I2C_CR2_ACK ((u8_t)0x04)
#define I2C_CR2_STOP ((u8_t)0x02)
#define I2C_CR2_START ((u8_t)0x01)

#define I2C_FREQR_FREQ ((u8_t)0x3F)

#define I2C_OARL_ADD ((u8_t)0xFE)
#define I2C_OARL_ADD0 ((u8_t)0x01)

#define I2C_OARH_ADDMODE ((u8_t)0x80)
#define I2C_OARH_ADDCONF ((u8_t)0x40)
#define I2C_OARH_ADD ((u8_t)0x06)

#define I2C_DR_DR ((u8_t)0xFF)

#define I2C_SR1_TXE ((u8_t)0x80)
#define I2C_SR1_RXNE ((u8_t)0x40)
#define I2C_SR1_STOPF ((u8_t)0x10)
#define I2C_SR1_ADD10 ((u8_t)0x08)
#define I2C_SR1_BTF ((u8_t)0x04)
#define I2C_SR1_ADDR ((u8_t)0x02)
#define I2C_SR1_SB ((u8_t)0x01)

#define I2C_SR2_WUFH ((u8_t)0x20)
#define I2C_SR2_OVR ((u8_t)0x08)
#define I2C_SR2_AF ((u8_t)0x04)
#define I2C_SR2_ARLO ((u8_t)0x02)
#define I2C_SR2_BERR ((u8_t)0x01)

#define I2C_SR3_GENCALL ((u8_t)0x10)
#define I2C_SR3_TRA ((u8_t)0x04)
#define I2C_SR3_BUSY ((u8_t)0x02)
#define I2C_SR3_MSL ((u8_t)0x01)

#define I2C_ITR_ITBUFEN ((u8_t)0x04)
#define I2C_ITR_ITEVTEN ((u8_t)0x02)
#define I2C_ITR_ITERREN ((u8_t)0x01)

#define I2C_CCRL_CCR ((u8_t)0xFF)

#define I2C_CCRH_FS ((u8_t)0x80)
#define I2C_CCRH_DUTY ((u8_t)0x40)
#define I2C_CCRH_CCR ((u8_t)0x0F)

#define I2C_TRISER_TRISE ((u8_t)0x3F)

struct stm8s_itc
{
    volatile u8_t ISPR1;
    volatile u8_t ISPR2;
    volatile u8_t ISPR3;
    volatile u8_t ISPR4;
    volatile u8_t ISPR5;
    volatile u8_t ISPR6;
    volatile u8_t ISPR7;
    volatile u8_t ISPR8;
};

#define ITC ((struct stm8s_itc*) 0x7F70)

#define CPU_CC_I1I0 ((u8_t)0x28)

struct stm8s_exti
{
    volatile u8_t CR1;
    volatile u8_t CR2;
};

#define EXTI ((struct stm8s_exti*)0x50A0)

#define EXTI_CR1_PDIS ((u8_t)0xC0)
#define EXTI_CR1_PCIS ((u8_t)0x30)
#define EXTI_CR1_PBIS ((u8_t)0x0C)
#define EXTI_CR1_PAIS ((u8_t)0x03)

#define EXTI_CR2_TLIS ((u8_t)0x04)
#define EXTI_CR2_PEIS ((u8_t)0x03)

struct stm8s_flash
{
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t NCR2;
    volatile u8_t FPR;
    volatile u8_t NFPR;
    volatile u8_t IAPSR;
    u8_t RESERVED1;
    u8_t RESERVED2;
    volatile u8_t PUKR;
    u8_t RESERVED3;
    volatile u8_t DUKR;
};

#define FLASH ((struct stm8s_flash*)0x505A)

#define FLASH_CR1_HALT ((u8_t)0x08)
#define FLASH_CR1_AHALT ((u8_t)0x04)
#define FLASH_CR1_IE ((u8_t)0x02)
#define FLASH_CR1_FIX ((u8_t)0x01)

#define FLASH_CR2_OPT ((u8_t)0x80)
#define FLASH_CR2_WPRG ((u8_t)0x40)
#define FLASH_CR2_ERASE ((u8_t)0x20)
#define FLASH_CR2_FPRG ((u8_t)0x10)
#define FLASH_CR2_PRG ((u8_t)0x01)

#define FLASH_NCR2_NOPT ((u8_t)0x80)
#define FLASH_NCR2_NWPRG ((u8_t)0x40)
#define FLASH_NCR2_NERASE ((u8_t)0x20)
#define FLASH_NCR2_NFPRG ((u8_t)0x10)
#define FLASH_NCR2_NPRG ((u8_t)0x01)

#define FLASH_IAPSR_HVOFF ((u8_t)0x40)
#define FLASH_IAPSR_DUL ((u8_t)0x08)
#define FLASH_IAPSR_EOP ((u8_t)0x04)
#define FLASH_IAPSR_PUL ((u8_t)0x02)
#define FLASH_IAPSR_WR_PG_DIS ((u8_t)0x01)

#define FLASH_PUKR_PUK ((u8_t)0xFF)

#define FLASH_DUKR_DUK ((u8_t)0xFF)

struct stm8s_opt
{
    volatile u8_t OPT0;
    volatile u8_t OPT1;
    volatile u8_t NOPT1;
    volatile u8_t OPT2;
    volatile u8_t NOPT2;
    volatile u8_t OPT3;
    volatile u8_t NOPT3;
    volatile u8_t OPT4;
    volatile u8_t NOPT4;
    volatile u8_t OPT5;
    volatile u8_t NOPT5;
    u8_t RESERVED1;
    u8_t RESERVED2;
    volatile u8_t OPT7;
    volatile u8_t NOPT7;
};

#define OPT ((struct stm8s_opt*)0x4800)

struct stm8s_iwdg
{
    volatile u8_t KR;
    volatile u8_t PR;
    volatile u8_t RLR;
};

#define IWDG ((struct stm8s_iwdg*) 0x50E0)

struct stm8s_wwdg
{
    volatile u8_t CR;
    volatile u8_t WR;
};

#define WWDG ((struct stm8s_wwdg*) 0x50D1)

#define WWDG_CR_WDGA ((u8_t)0x80)
#define WWDG_CR_T6 ((u8_t)0x40)
#define WWDG_CR_T ((u8_t)0x7F)

#define WWDG_WR_MSB ((u8_t)0x80)
#define WWDG_WR_W ((u8_t)0x7F)

struct stm8s_rst
{
    volatile u8_t SR;
};

#define RST ((struct stm8s_rst*) 0x50B3)

#define RST_SR_EMCF ((u8_t)0x10)
#define RST_SR_SWIMF ((u8_t)0x08)
#define RST_SR_ILLOPF ((u8_t)0x04)
#define RST_SR_IWDGF ((u8_t)0x02)
#define RST_SR_WWDGF ((u8_t)0x01)

struct stm8s_spi
{
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t ICR;
    volatile u8_t SR;
    volatile u8_t DR;
    volatile u8_t CRCPR;
    volatile u8_t RXCRCR;
    volatile u8_t TXCRCR;
};

#define SPI ((struct stm8s_spi*) 0x5200)

#define SPI_CR1_LSBFIRST ((u8_t)0x80)
#define SPI_CR1_SPE ((u8_t)0x40)
#define SPI_CR1_BR ((u8_t)0x38)
#define SPI_CR1_MSTR ((u8_t)0x04)
#define SPI_CR1_CPOL ((u8_t)0x02)
#define SPI_CR1_CPHA ((u8_t)0x01)

#define SPI_CR2_BDM ((u8_t)0x80)
#define SPI_CR2_BDOE ((u8_t)0x40)
#define SPI_CR2_CRCEN ((u8_t)0x20)
#define SPI_CR2_CRCNEXT ((u8_t)0x10)
#define SPI_CR2_RXONLY ((u8_t)0x04)
#define SPI_CR2_SSM ((u8_t)0x02)
#define SPI_CR2_SSI ((u8_t)0x01)

#define SPI_ICR_TXEI ((u8_t)0x80)
#define SPI_ICR_RXEI ((u8_t)0x40)
#define SPI_ICR_ERRIE ((u8_t)0x20)
#define SPI_ICR_WKIE ((u8_t)0x10)

#define SPI_SR_BSY ((u8_t)0x80)
#define SPI_SR_OVR ((u8_t)0x40)
#define SPI_SR_MODF ((u8_t)0x20)
#define SPI_SR_CRCERR ((u8_t)0x10)
#define SPI_SR_WKUP ((u8_t)0x08)
#define SPI_SR_TXE ((u8_t)0x02)
#define SPI_SR_RXNE ((u8_t)0x01)

struct stm8s_uart1
{
    volatile u8_t SR;
    volatile u8_t DR;
    volatile u8_t BRR1;
    volatile u8_t BRR2;
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t CR3;
    volatile u8_t CR4;
    volatile u8_t CR5;
    volatile u8_t GTR;
    volatile u8_t PSCR;
};

#define UART1 ((struct stm8s_uart1*) 0x5230)

#define UART1_SR_TXE ((u8_t)0x80)
#define UART1_SR_TC ((u8_t)0x40)
#define UART1_SR_RXNE ((u8_t)0x20)
#define UART1_SR_IDLE ((u8_t)0x10)
#define UART1_SR_OR ((u8_t)0x08)
#define UART1_SR_NF ((u8_t)0x04)
#define UART1_SR_FE ((u8_t)0x02)
#define UART1_SR_PE ((u8_t)0x01)

#define UART1_BRR1_DIVM ((u8_t)0xFF)

#define UART1_BRR2_DIVM ((u8_t)0xF0)
#define UART1_BRR2_DIVF ((u8_t)0x0F)

#define UART1_CR1_R8 ((u8_t)0x80)
#define UART1_CR1_T8 ((u8_t)0x40)
#define UART1_CR1_UARTD ((u8_t)0x20)
#define UART1_CR1_M ((u8_t)0x10)
#define UART1_CR1_WAKE ((u8_t)0x08)
#define UART1_CR1_PCEN ((u8_t)0x04)
#define UART1_CR1_PS ((u8_t)0x02)
#define UART1_CR1_PIEN ((u8_t)0x01)

#define UART1_CR2_TIEN ((u8_t)0x80)
#define UART1_CR2_TCIEN ((u8_t)0x40)
#define UART1_CR2_RIEN ((u8_t)0x20)
#define UART1_CR2_ILIEN ((u8_t)0x10)
#define UART1_CR2_TEN ((u8_t)0x08)
#define UART1_CR2_REN ((u8_t)0x04)
#define UART1_CR2_RWU ((u8_t)0x02)
#define UART1_CR2_SBK ((u8_t)0x01)

#define UART1_CR3_LINEN ((u8_t)0x40)
#define UART1_CR3_STOP ((u8_t)0x30)
#define UART1_CR3_CKEN ((u8_t)0x08)
#define UART1_CR3_CPOL ((u8_t)0x04)
#define UART1_CR3_CPHA ((u8_t)0x02)
#define UART1_CR3_LBCL ((u8_t)0x01)

#define UART1_CR4_LBDIEN ((u8_t)0x40)
#define UART1_CR4_LBDL ((u8_t)0x20)
#define UART1_CR4_LBDF ((u8_t)0x10)
#define UART1_CR4_ADD ((u8_t)0x0F)

#define UART1_CR5_SCEN ((u8_t)0x20)
#define UART1_CR5_NACK ((u8_t)0x10)
#define UART1_CR5_HDSEL ((u8_t)0x08)
#define UART1_CR5_IRLP ((u8_t)0x04)
#define UART1_CR5_IREN ((u8_t)0x02)

struct stm8s_uart2
{
    volatile u8_t SR;
    volatile u8_t DR;
    volatile u8_t BRR1;
    volatile u8_t BRR2;
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t CR3;
    volatile u8_t CR4;
    volatile u8_t CR5;
    volatile u8_t CR6;
    volatile u8_t GTR;
    volatile u8_t PSCR;
};

#define UART2 ((struct stm8s_uart2*) 0x5240)

#define UART2_SR_TXE ((u8_t)0x80)
#define UART2_SR_TC ((u8_t)0x40)
#define UART2_SR_RXNE ((u8_t)0x20)
#define UART2_SR_IDLE ((u8_t)0x10)
#define UART2_SR_OR ((u8_t)0x08)
#define UART2_SR_NF ((u8_t)0x04)
#define UART2_SR_FE ((u8_t)0x02)
#define UART2_SR_PE ((u8_t)0x01)

#define UART2_BRR1_DIVM ((u8_t)0xFF)

#define UART2_BRR2_DIVM ((u8_t)0xF0)
#define UART2_BRR2_DIVF ((u8_t)0x0F)

#define UART2_CR1_R8 ((u8_t)0x80)
#define UART2_CR1_T8 ((u8_t)0x40)
#define UART2_CR1_UARTD ((u8_t)0x20)
#define UART2_CR1_M ((u8_t)0x10)
#define UART2_CR1_WAKE ((u8_t)0x08)
#define UART2_CR1_PCEN ((u8_t)0x04)
#define UART2_CR1_PS ((u8_t)0x02)
#define UART2_CR1_PIEN ((u8_t)0x01)

#define UART2_CR2_TIEN ((u8_t)0x80)
#define UART2_CR2_TCIEN ((u8_t)0x40)
#define UART2_CR2_RIEN ((u8_t)0x20)
#define UART2_CR2_ILIEN ((u8_t)0x10)
#define UART2_CR2_TEN ((u8_t)0x08)
#define UART2_CR2_REN ((u8_t)0x04)
#define UART2_CR2_RWU ((u8_t)0x02)
#define UART2_CR2_SBK ((u8_t)0x01)

#define UART2_CR3_LINEN ((u8_t)0x40)
#define UART2_CR3_STOP ((u8_t)0x30)
#define UART2_CR3_CKEN ((u8_t)0x08)
#define UART2_CR3_CPOL ((u8_t)0x04)
#define UART2_CR3_CPHA ((u8_t)0x02)
#define UART2_CR3_LBCL ((u8_t)0x01)

#define UART2_CR4_LBDIEN ((u8_t)0x40)
#define UART2_CR4_LBDL ((u8_t)0x20)
#define UART2_CR4_LBDF ((u8_t)0x10)
#define UART2_CR4_ADD ((u8_t)0x0F)

#define UART2_CR5_SCEN ((u8_t)0x20)
#define UART2_CR5_NACK ((u8_t)0x10)
#define UART2_CR5_HDSEL ((u8_t)0x08)
#define UART2_CR5_IRLP ((u8_t)0x04)
#define UART2_CR5_IREN ((u8_t)0x02)

#define UART2_CR6_LDUM ((u8_t)0x80)
#define UART2_CR6_LSLV ((u8_t)0x20)
#define UART2_CR6_LASE ((u8_t)0x10)
#define UART2_CR6_LHDIEN ((u8_t)0x04)
#define UART2_CR6_LHDF ((u8_t)0x02)
#define UART2_CR6_LSF ((u8_t)0x01)

struct stm8s_uart3
{
    volatile u8_t SR;
    volatile u8_t DR;
    volatile u8_t BRR1;
    volatile u8_t BRR2;
    volatile u8_t CR1;
    volatile u8_t CR2;
    volatile u8_t CR3;
    volatile u8_t CR4;
    u8_t RESERVED;
    volatile u8_t CR6;
};

#define UART3 ((struct stm8s_uart3*) 0x5240)

#define UART3_SR_TXE ((u8_t)0x80)
#define UART3_SR_TC ((u8_t)0x40)
#define UART3_SR_RXNE ((u8_t)0x20)
#define UART3_SR_IDLE ((u8_t)0x10)
#define UART3_SR_OR ((u8_t)0x08)
#define UART3_SR_NF ((u8_t)0x04)
#define UART3_SR_FE ((u8_t)0x02)
#define UART3_SR_PE ((u8_t)0x01)

#define UART3_BRR1_DIVM ((u8_t)0xFF)

#define UART3_BRR2_DIVM ((u8_t)0xF0)
#define UART3_BRR2_DIVF ((u8_t)0x0F)

#define UART3_CR1_R8 ((u8_t)0x80)
#define UART3_CR1_T8 ((u8_t)0x40)
#define UART3_CR1_UARTD ((u8_t)0x20)
#define UART3_CR1_M ((u8_t)0x10)
#define UART3_CR1_WAKE ((u8_t)0x08)
#define UART3_CR1_PCEN ((u8_t)0x04)
#define UART3_CR1_PS ((u8_t)0x02)
#define UART3_CR1_PIEN ((u8_t)0x01)

#define UART3_CR2_TIEN ((u8_t)0x80)
#define UART3_CR2_TCIEN ((u8_t)0x40)
#define UART3_CR2_RIEN ((u8_t)0x20)
#define UART3_CR2_ILIEN ((u8_t)0x10)
#define UART3_CR2_TEN ((u8_t)0x08)
#define UART3_CR2_REN ((u8_t)0x04)
#define UART3_CR2_RWU ((u8_t)0x02)
#define UART3_CR2_SBK ((u8_t)0x01)

#define UART3_CR3_LINEN ((u8_t)0x40)
#define UART3_CR3_STOP ((u8_t)0x30)

#define UART3_CR4_LBDIEN ((u8_t)0x40)
#define UART3_CR4_LBDL ((u8_t)0x20)
#define UART3_CR4_LBDF ((u8_t)0x10)
#define UART3_CR4_ADD ((u8_t)0x0F)

#define UART3_CR6_LDUM ((u8_t)0x80)
#define UART3_CR6_LSLV ((u8_t)0x20)
#define UART3_CR6_LASE ((u8_t)0x10)
#define UART3_CR6_LHDIEN ((u8_t)0x04)
#define UART3_CR6_LHDF ((u8_t)0x02)
#define UART3_CR6_LSF ((u8_t)0x01)

struct stm8s_can
{
    volatile u8_t MCR;
    volatile u8_t MSR;
    volatile u8_t TSR;
    volatile u8_t TPR;
    volatile u8_t RFR;
    volatile u8_t IER;
    volatile u8_t DGR;
    volatile u8_t PSR;
    union
    {
        struct
        {
            volatile u8_t MCSR;
            volatile u8_t MDLCR;
            volatile u8_t MIDR1;
            volatile u8_t MIDR2;
            volatile u8_t MIDR3;
            volatile u8_t MIDR4;
            volatile u8_t MDAR1;
            volatile u8_t MDAR2;
            volatile u8_t MDAR3;
            volatile u8_t MDAR4;
            volatile u8_t MDAR5;
            volatile u8_t MDAR6;
            volatile u8_t MDAR7;
            volatile u8_t MDAR8;
            volatile u8_t MTSRL;
            volatile u8_t MTSRH;
        } TXB;
        struct
        {
            volatile u8_t FR01;
            volatile u8_t FR02;
            volatile u8_t FR03;
            volatile u8_t FR04;
            volatile u8_t FR05;
            volatile u8_t FR06;
            volatile u8_t FR07;
            volatile u8_t FR08;
            volatile u8_t FR09;
            volatile u8_t FR10;
            volatile u8_t FR11;
            volatile u8_t FR12;
            volatile u8_t FR13;
            volatile u8_t FR14;
            volatile u8_t FR15;
            volatile u8_t FR16;
        } F;
        struct
        {
            volatile u8_t F0R1;
            volatile u8_t F0R2;
            volatile u8_t F0R3;
            volatile u8_t F0R4;
            volatile u8_t F0R5;
            volatile u8_t F0R6;
            volatile u8_t F0R7;
            volatile u8_t F0R8;
            volatile u8_t F1R1;
            volatile u8_t F1R2;
            volatile u8_t F1R3;
            volatile u8_t F1R4;
            volatile u8_t F1R5;
            volatile u8_t F1R6;
            volatile u8_t F1R7;
            volatile u8_t F1R8;
        } F01;
        struct
        {
            volatile u8_t F2R1;
            volatile u8_t F2R2;
            volatile u8_t F2R3;
            volatile u8_t F2R4;
            volatile u8_t F2R5;
            volatile u8_t F2R6;
            volatile u8_t F2R7;
            volatile u8_t F2R8;
            volatile u8_t F3R1;
            volatile u8_t F3R2;
            volatile u8_t F3R3;
            volatile u8_t F3R4;
            volatile u8_t F3R5;
            volatile u8_t F3R6;
            volatile u8_t F3R7;
            volatile u8_t F3R8;
        } F23;
        struct
        {
            volatile u8_t F4R1;
            volatile u8_t F4R2;
            volatile u8_t F4R3;
            volatile u8_t F4R4;
            volatile u8_t F4R5;
            volatile u8_t F4R6;
            volatile u8_t F4R7;
            volatile u8_t F4R8;
            volatile u8_t F5R1;
            volatile u8_t F5R2;
            volatile u8_t F5R3;
            volatile u8_t F5R4;
            volatile u8_t F5R5;
            volatile u8_t F5R6;
            volatile u8_t F5R7;
            volatile u8_t F5R8;
        } F45;
        struct
        {
            volatile u8_t ESR;
            volatile u8_t EIER;
            volatile u8_t TECR;
            volatile u8_t RECR;
            volatile u8_t BTR1;
            volatile u8_t BTR2;
            u8_t RESERVED1[2];
            volatile u8_t FMR1;
            volatile u8_t FMR2;
            volatile u8_t FCR1;
            volatile u8_t FCR2;
            volatile u8_t FCR3;
            u8_t RESERVED2[3];
        } CFG;
        struct
        {
            volatile u8_t MFMI;
            volatile u8_t MDLCR;
            volatile u8_t MIDR1;
            volatile u8_t MIDR2;
            volatile u8_t MIDR3;
            volatile u8_t MIDR4;
            volatile u8_t MDAR1;
            volatile u8_t MDAR2;
            volatile u8_t MDAR3;
            volatile u8_t MDAR4;
            volatile u8_t MDAR5;
            volatile u8_t MDAR6;
            volatile u8_t MDAR7;
            volatile u8_t MDAR8;
            volatile u8_t MTSRL;
            volatile u8_t MTSRH;
        } RXF;
    } P;
};

#define CAN ((struct stm8s_can*) 0x5420)

#define CAN_MCR_INRQ ((u8_t)0x01)
#define CAN_MCR_SLEEP ((u8_t)0x02)
#define CAN_MCR_TXFP ((u8_t)0x04)
#define CAN_MCR_RFLM ((u8_t)0x08)
#define CAN_MCR_NART ((u8_t)0x10)
#define CAN_MCR_AWUM ((u8_t)0x20)
#define CAN_MCR_ABOM ((u8_t)0x40)
#define CAN_MCR_TTCM ((u8_t)0x80)

#define CAN_MSR_INAK ((u8_t)0x01)
#define CAN_MSR_SLAK ((u8_t)0x02)
#define CAN_MSR_ERRI ((u8_t)0x04)
#define CAN_MSR_WKUI ((u8_t)0x08)
#define CAN_MSR_TX ((u8_t)0x10)
#define CAN_MSR_RX ((u8_t)0x20)

#define CAN_TSR_RQCP0 ((u8_t)0x01)
#define CAN_TSR_RQCP1 ((u8_t)0x02)
#define CAN_TSR_RQCP2 ((u8_t)0x04)
#define CAN_TSR_RQCP012 ((u8_t)0x07)
#define CAN_TSR_TXOK0 ((u8_t)0x10)
#define CAN_TSR_TXOK1 ((u8_t)0x20)
#define CAN_TSR_TXOK2 ((u8_t)0x40)

#define CAN_TPR_CODE0 ((u8_t)0x01)
#define CAN_TPR_TME0 ((u8_t)0x04)
#define CAN_TPR_TME1 ((u8_t)0x08)
#define CAN_TPR_TME2 ((u8_t)0x10)
#define CAN_TPR_LOW0 ((u8_t)0x20)
#define CAN_TPR_LOW1 ((u8_t)0x40)
#define CAN_TPR_LOW2 ((u8_t)0x80)

#define CAN_RFR_FMP01 ((u8_t)0x03)
#define CAN_RFR_FULL ((u8_t)0x08)
#define CAN_RFR_FOVR ((u8_t)0x10)
#define CAN_RFR_RFOM ((u8_t)0x20)

#define CAN_IER_TMEIE ((u8_t)0x01)
#define CAN_IER_FMPIE ((u8_t)0x02)
#define CAN_IER_FFIE ((u8_t)0x04)
#define CAN_IER_FOVIE ((u8_t)0x08)
#define CAN_IER_WKUIE ((u8_t)0x80)

#define CAN_DGR_LBKM ((u8_t)0x01)
#define CAN_DGR_SLIM ((u8_t)0x02)
#define CAN_DGR_SAMP ((u8_t)0x04)
#define CAN_DGR_RX ((u8_t)0x08)
#define CAN_DGR_TXM2E ((u8_t)0x10)

#define CAN_PSR_PS0 ((u8_t)0x01)
#define CAN_PSR_PS1 ((u8_t)0x02)
#define CAN_PSR_PS2 ((u8_t)0x04)

#define CAN_MCSR_TXRQ ((u8_t)0x01)
#define CAN_MCSR_ABRQ ((u8_t)0x02)
#define CAN_MCSR_RQCP ((u8_t)0x04)
#define CAN_MCSR_TXOK ((u8_t)0x08)
#define CAN_MCSR_ALST ((u8_t)0x10)
#define CAN_MCSR_TERR ((u8_t)0x20)

#define CAN_MDLCR_DLC ((u8_t)0x0F)
#define CAN_MDLCR_TGT ((u8_t)0x80)

#define CAN_MIDR1_RTR ((u8_t)0x20)
#define CAN_MIDR1_IDE ((u8_t)0x40)

#define CAN_ESR_EWGF ((u8_t)0x01)
#define CAN_ESR_EPVF ((u8_t)0x02)
#define CAN_ESR_BOFF ((u8_t)0x04)
#define CAN_ESR_LEC0 ((u8_t)0x10)
#define CAN_ESR_LEC1 ((u8_t)0x20)
#define CAN_ESR_LEC2 ((u8_t)0x40)
#define CAN_ESR_LEC ((u8_t)0x70)

#define CAN_EIER_EWGIE ((u8_t)0x01)
#define CAN_EIER_EPVIE ((u8_t)0x02)
#define CAN_EIER_BOFIE ((u8_t)0x04)
#define CAN_EIER_LECIE ((u8_t)0x10)
#define CAN_EIER_ERRIE ((u8_t)0x80)

#define CAN_TECR_TEC0 ((u8_t)0x01)
#define CAN_TECR_TEC1 ((u8_t)0x02)
#define CAN_TECR_TEC2 ((u8_t)0x04)
#define CAN_TECR_TEC3 ((u8_t)0x08)
#define CAN_TECR_TEC4 ((u8_t)0x10)
#define CAN_TECR_TEC5 ((u8_t)0x20)
#define CAN_TECR_TEC6 ((u8_t)0x40)
#define CAN_TECR_TEC7 ((u8_t)0x80)

#define CAN_RECR_REC0 ((u8_t)0x01)
#define CAN_RECR_REC1 ((u8_t)0x02)
#define CAN_RECR_REC2 ((u8_t)0x04)
#define CAN_RECR_REC3 ((u8_t)0x08)
#define CAN_RECR_REC4 ((u8_t)0x10)
#define CAN_RECR_REC5 ((u8_t)0x20)
#define CAN_RECR_REC6 ((u8_t)0x40)
#define CAN_RECR_REC7 ((u8_t)0x80)

#define CAN_FMR1_FML0 ((u8_t)0x01)
#define CAN_FMR1_FMH0 ((u8_t)0x02)
#define CAN_FMR1_FML1 ((u8_t)0x04)
#define CAN_FMR1_FMH1 ((u8_t)0x08)
#define CAN_FMR1_FML2 ((u8_t)0x10)
#define CAN_FMR1_FMH2 ((u8_t)0x20)
#define CAN_FMR1_FML3 ((u8_t)0x40)
#define CAN_FMR1_FMH3 ((u8_t)0x80)

#define CAN_FMR2_FML4 ((u8_t)0x01)
#define CAN_FMR2_FMH4 ((u8_t)0x02)
#define CAN_FMR2_FML5 ((u8_t)0x04)
#define CAN_FMR2_FMH5 ((u8_t)0x08)

#define CAN_FCR1_FACT0 ((u8_t)0x01)
#define CAN_FCR1_FACT1 ((u8_t)0x10)
#define CAN_FCR2_FACT2 ((u8_t)0x01)
#define CAN_FCR2_FACT3 ((u8_t)0x10)
#define CAN_FCR3_FACT4 ((u8_t)0x01)
#define CAN_FCR3_FACT5 ((u8_t)0x10)
#define CAN_FCR1_FSC00 ((u8_t)0x02)
#define CAN_FCR1_FSC01 ((u8_t)0x04)
#define CAN_FCR1_FSC10 ((u8_t)0x20)
#define CAN_FCR1_FSC11 ((u8_t)0x40)
#define CAN_FCR2_FSC20 ((u8_t)0x02)
#define CAN_FCR2_FSC21 ((u8_t)0x04)
#define CAN_FCR2_FSC30 ((u8_t)0x20)
#define CAN_FCR2_FSC31 ((u8_t)0x40)
#define CAN_FCR3_FSC40 ((u8_t)0x02)
#define CAN_FCR3_FSC41 ((u8_t)0x04)
#define CAN_FCR3_FSC50 ((u8_t)0x20)
#define CAN_FCR3_FSC51 ((u8_t)0x40)

struct stm8s_cfg
{
    volatile u8_t GCR;
};

#define CFG ((struct stm8s_cfg*) 0x7F60)

#define CFG_GCR_SWD ((u8_t)0x01)
#define CFG_GCR_AL ((u8_t)0x02)

#define DM ((struct stm8s_dm*) 0x7F90)

#endif
