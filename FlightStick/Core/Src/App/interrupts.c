#include "main.h"
#include "resistors.h"
#include "buttons.h"

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	if(hadc->Instance == ADC1){
		Resistors_Interrupt();
	}
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if((GPIO_Pin == BUTTON_1_Pin) || (GPIO_Pin == BUTTON_2_Pin)){
		Buttons_Interrupt(GPIO_Pin);
	}
}