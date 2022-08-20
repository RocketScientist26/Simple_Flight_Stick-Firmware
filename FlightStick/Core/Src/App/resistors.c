#include "main.h"
#include "resistors.h"

extern ADC_HandleTypeDef hadc1;

struct resistors{
	uint8_t ready;
	uint16_t x;
	uint16_t y;
	uint16_t buffer[200];
}resistors;

void Resistors_Interrupt(){
	HAL_ADC_Stop_DMA(&hadc1);
	CLEAR_BIT(hadc1.State, HAL_ADC_STATE_ERROR_DMA);
	resistors.ready = 1;
}
void Resistors_Start(){
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&resistors.buffer[0], 200);
}

void Resistors_Get(int8_t *x, int8_t *y){
	//Calculate median
	uint64_t sum = 0;
	uint16_t i = 0;
	while(i < 200){
		sum += resistors.buffer[i];
		i += 2;
	}
	resistors.x = (uint16_t)((uint64_t)sum / 100);
	sum = 0;
	i = 1;
	while(i < 200){
		sum += resistors.buffer[i];
		i += 2;
	}
	resistors.y = (uint16_t)((uint64_t)sum / 100);

	//Convert for -127 0 +127 scale
	int8_t tmp = (float)resistors.x / (4096.0f / 255.0f);
	if((tmp >= 0) && (tmp <= 126)){
		tmp = -(127 - tmp);
	}else if((tmp >= -128) && (tmp <= -2)){
		tmp += 129;
	}else if(tmp == 127){
		tmp = 0;
	}
	*x = tmp;

	tmp = (float)resistors.y / (4096.0f / 255.0f);
	if((tmp >= 0) && (tmp <= 126)){
		tmp = -(127 - tmp);
	}else if((tmp >= -128) && (tmp <= -2)){
		tmp += 129;
	}else if(tmp == 127){
		tmp = 0;
	}
	*y = tmp;

	Resistors_Start();
}
uint8_t Resistors_Ready(){
	if(resistors.ready){
		resistors.ready = 0;
		return 1;
	}
	return 0;
}
void Resistors_Init(){
	HAL_ADCEx_Calibration_Start(&hadc1);
	Resistors_Start();
}