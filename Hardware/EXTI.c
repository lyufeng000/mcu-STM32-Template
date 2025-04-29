#include "EXTI.h"

#define GPIO_Port_Source 		GPIO_PortSourceGPIOB
#define GPIO_Pin_Source 		GPIO_PinSource12
#define GPIO_Port 				GPIOB
#define GPIO_Pin 				GPIO_Pin_12
#define GPIO_Speed 				GPIO_Speed_50MHz
#define GPIO_Mode 				GPIO_Mode_IPU
#define Line 					EXTI_Line12
#define IRQChannel 				EXTI15_10_IRQn
#define PreemptionPriority 		1
#define SubPriority 			1

void Init_EXTI(void) {
	GPIO_Toggle(GPIOB, GPIO_Pin_0);//亮起
	if (GPIO_Port == GPIOA) {
		Init_GPIOA(GPIO_Pin, GPIO_Speed, GPIO_Mode);
	} else if (GPIO_Port == GPIOB){
		GPIO_Toggle(GPIOB, GPIO_Pin_0);//熄灭
		Init_GPIOB(GPIO_Pin, GPIO_Speed, GPIO_Mode);
	} else if (GPIO_Port == GPIOC) {
		Init_GPIOC(GPIO_Pin, GPIO_Speed, GPIO_Mode);
	}
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_EXTILineConfig(GPIO_Port_Source, GPIO_Pin_Source);
	
	GPIO_Toggle(GPIOB, GPIO_Pin_0);//亮起
	EXTI_InitTypeDef extiInit;
	extiInit.EXTI_Line = Line;
	extiInit.EXTI_LineCmd = ENABLE;
	extiInit.EXTI_Mode = EXTI_Mode_Interrupt;
	extiInit.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&extiInit);
	
	GPIO_Toggle(GPIOB, GPIO_Pin_0);//熄灭
	NVIC_InitTypeDef nvicInit;
	nvicInit.NVIC_IRQChannel = IRQChannel;
	nvicInit.NVIC_IRQChannelCmd = ENABLE;
	nvicInit.NVIC_IRQChannelPreemptionPriority = PreemptionPriority;
	nvicInit.NVIC_IRQChannelSubPriority = SubPriority;
	NVIC_Init(&nvicInit);
	GPIO_Toggle(GPIOB, GPIO_Pin_0);//亮起
	GPIO_Toggle(GPIOB, GPIO_Pin_0);//熄灭
}

void Init_Group(uint32_t NVIC_PriorityGroup) {
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup);
}

//中断0
void EXTI0_IRQHandler(void) {
	if(EXTI_GetITStatus(EXTI_Line0) == SET) {
		
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
}

//中断1
void EXTI1_IRQHandler(void) {
	if(EXTI_GetITStatus(EXTI_Line1) == SET) {
		
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
}

//中断2
void EXTI2_IRQHandler(void) {
	if(EXTI_GetITStatus(EXTI_Line2) == SET) {
		
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
}

//中断3
void EXTI3_IRQHandler(void) {
	if(EXTI_GetITStatus(EXTI_Line3) == SET) {
		
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
}

//中断4
void EXTI4_IRQHandler(void) {
	if(EXTI_GetITStatus(EXTI_Line4) == SET) {
		
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
}

//中断5-9
void EXTI9_5_IRQHandler(void) {
	
}

//中断10-15
void EXTI15_10_IRQHandler(void) {
	if(EXTI_GetITStatus(EXTI_Line12) == SET) {
		GPIO_Toggle(GPIOA, GPIO_Pin_6);
		GPIO_Toggle(GPIOA, GPIO_Pin_7);
		GPIO_Toggle(GPIOB, GPIO_Pin_0);
		EXTI_ClearITPendingBit(EXTI_Line12);
	}
}












