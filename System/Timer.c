#include "Timer.h"

void Init_Timer(void) {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	
	//时基单元初始化
	TIM_TimeBaseInitTypeDef tbInit;
	tbInit.TIM_ClockDivision = TIM_CKD_DIV1;
	tbInit.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
	/*这三个值是时基单元最重要的三个值*/
	//公式 CK_PSC / (PSC + 1) / (ARR + 1)
	//72Mhz / 7200 / 10000 = 1s
	//流程 72MHz先分频7200，以10000Hz的频率记10000个数，就是1s
	tbInit.TIM_Period = 10000 - 1;//ARR自动重装器的值
	tbInit.TIM_Prescaler = 7200 - 1;//PSC预分频器的值
	tbInit.TIM_RepetitionCounter = 0;//重复计数器的值（是高级计数器的参数）
	TIM_TimeBaseInit(TIM2, &tbInit);
	
	//配置输出中断控制
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	//配置中断
	NVIC_InitTypeDef init;
	init.NVIC_IRQChannel = TIM2_IRQn;
	init.NVIC_IRQChannelCmd = ENABLE;
	init.NVIC_IRQChannelPreemptionPriority = 0;
	init.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&init);
	
	//启动定时器
	TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void) {
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) {
		toggle(GPIOA, GPIO_Pin_6);
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
