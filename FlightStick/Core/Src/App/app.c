#include "main.h"
#include "app.h"
#include "resistors.h"
#include "buttons.h"
#include "backlight.h"
#include "usb.h"

struct app{
	int8_t x;
	int8_t y;
	uint8_t button_1;
	uint8_t button_2;
	uint8_t backlight;
}app;

void App_Init(){
	//Resistors
	Resistors_Init();
	while(!Resistors_Ready());
	Resistors_Get(&app.x, &app.y);
	//Buttons
	app.button_1 = Buttons_Read(BUTTON_1_Pin);
	app.button_2 = Buttons_Read(BUTTON_2_Pin);
	//Backlight
	Backlight_Init();
	app.backlight = Backlight_Get();
}
void App_Loop(){
	//Resistors
	if(Resistors_Ready()){
		Resistors_Get(&app.x, &app.y);
	}
	//Buttons
	if(Buttons_Pressed(BUTTON_1_Pin)){
		app.button_1 = Buttons_Read(BUTTON_1_Pin);
	}
	if(Buttons_Pressed(BUTTON_2_Pin)){
		app.button_2 = Buttons_Read(BUTTON_2_Pin);
	}
	//USB
	if(USB_Received()){
		Backlight_Set(USB_Read_Brightness());
	}
	//Backlight
	app.backlight = Backlight_Get();

	USB_Send(app.x, app.y, app.button_1, app.button_2, app.backlight);
}