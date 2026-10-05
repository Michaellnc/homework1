#include "task.h"
#include "main.h"
#include "iwdg.h"
#include "tim.h"

//1=GPIO，2=定时器+喂狗，3=看门狗不喂狗
#define TASK_MODE 3
volatile uint32_t tick=0;

void Task_Init(void)
{
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    #if TASK_MODE>=2
    HAL_TIM_Base_Start_IT(&htim2);
    #endif
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance==TIM2)
    {
        tick++;
        #if TASK_MODE==2
        HAL_IWDG_Refresh(&hiwdg);
        #endif
    }
}