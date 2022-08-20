#include "main.h"
#include "buttons.h"

static uint8_t buttons_pressed_1 = 0;
static uint8_t buttons_pressed_2 = 0;

void Buttons_Interrupt(uint16_t GPIO_Pin){
	if(GPIO_Pin == BUTTON_1_Pin){
		buttons_pressed_1 = 1;
	}else if(GPIO_Pin == BUTTON_2_Pin){
		buttons_pressed_2 = 1;
	}
}
uint8_t Buttons_Debounce_Read(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin){
	uint8_t level;
	uint8_t d = 0;
	uint8_t i = 0;
	while(d != 1){
		i = 0;
		level = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
		while(i != BUTTON_DEBOUNCE_SAMPLES){
			i++;
			if(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) != level){
				break;
			}
			if(i == BUTTON_DEBOUNCE_SAMPLES){
				d = 1;
			}
		}
	}
	return level;
}
uint8_t Buttons_Pressed(uint16_t GPIO_Pin){
	uint8_t ret = 0;
	switch(GPIO_Pin){
		case BUTTON_1_Pin:
			ret = buttons_pressed_1;
			buttons_pressed_1 = 0;
		break;
		case BUTTON_2_Pin:
			ret = buttons_pressed_2;
			buttons_pressed_2 = 0;
		break;
	}
	return ret;
}
uint8_t Buttons_Read(uint16_t GPIO_Pin){
	switch(GPIO_Pin){
		case BUTTON_1_Pin:
			return 1 - Buttons_Debounce_Read(GPIOA, BUTTON_1_Pin);
		break;
		case BUTTON_2_Pin:
			return 1 - Buttons_Debounce_Read(GPIOA, BUTTON_2_Pin);
		break;
	}
	return 0;
}