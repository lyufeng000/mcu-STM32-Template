#ifndef __GPIOINIT_H
#define __GPIOINIT_H

#include "stm32f10x.h"

void Init_GPIOA(uint16_t Pin, GPIOSpeed_TypeDef Speed, GPIOMode_TypeDef Mode);
void Init_GPIOB(uint16_t Pin, GPIOSpeed_TypeDef Speed, GPIOMode_TypeDef Mode);
void Init_GPIOC(uint16_t Pin, GPIOSpeed_TypeDef Speed, GPIOMode_TypeDef Mode);

void toggle(GPIO_TypeDef *GPIOx, uint16_t Pin);





















#endif
