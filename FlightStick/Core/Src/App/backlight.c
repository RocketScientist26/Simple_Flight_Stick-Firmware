#include "main.h"
#include "backlight.h"

extern TIM_HandleTypeDef htim3;

uint8_t Backlight_Get(){
	return (uint8_t)__HAL_TIM_GET_COMPARE(&htim3, TIM_CHANNEL_1);
}
void Backlight_Set(uint16_t backlight){
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, backlight);
}
void Backlight_Init(){
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	uint8_t i = 0;
	while(i != 100){
		i++;
		HAL_Delay(10);
		htim3.Instance->CCR1 = i;
	}
}