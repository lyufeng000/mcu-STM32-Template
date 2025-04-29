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

//寄存器置1
void GPIO_Set(GPIO_TypeDef *GPIOx, uint32_t Pin) {
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(Pin));
	
	GPIOx->BSRR = Pin;
}

//寄存器置0
void GPIO_Reset(GPIO_TypeDef *GPIOx, uint32_t Pin) {
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(Pin));
	
	GPIOx->BSRR = Pin << 16;
}

//寄存器翻转
void GPIO_Toggle(GPIO_TypeDef *GPIOx, uint32_t Pins) {
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN(Pins));
	
	uint32_t odr = GPIOx->ODR;
	
	uint16_t pins = Pins;
	
	//低电平的引脚，要拉高
	uint32_t set_pins = (~odr) & pins;
	
	//高电平的引脚，要拉低
	uint32_t reset_pins = odr & pins;
	
	GPIOx->BSRR = set_pins | (uint32_t)reset_pins << 16;
}
