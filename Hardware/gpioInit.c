#include "gpioInit.h"

void Init_GPIOA(uint16_t Pin, GPIOSpeed_TypeDef Speed, GPIOMode_TypeDef Mode) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef init;
	init.GPIO_Mode = Mode;
	init.GPIO_Pin =Pin;
	init.GPIO_Speed = Speed;
	GPIO_Init(GPIOA, &init);
}

void Init_GPIOB(uint16_t Pin, GPIOSpeed_TypeDef Speed, GPIOMode_TypeDef Mode) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef init;
	init.GPIO_Mode = Mode;
	init.GPIO_Pin =Pin;
	init.GPIO_Speed = Speed;
	GPIO_Init(GPIOB, &init);
}

void Init_GPIOC(uint16_t Pin, GPIOSpeed_TypeDef Speed, GPIOMode_TypeDef Mode) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef init;
	init.GPIO_Mode = Mode;
	init.GPIO_Pin =Pin;
	init.GPIO_Speed = Speed;
	GPIO_Init(GPIOC, &init);
}






void toggle(GPIO_TypeDef *GPIOx, uint16_t Pin) {
	GPIOx->ODR ^= Pin;
}
