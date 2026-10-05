#ifndef TASK_H
#define TASK_H

#include "main.h"

void Task_Init(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
#endif // TASK_H