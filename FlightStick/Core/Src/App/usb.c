#include "main.h"
#include "usbd_custom_hid_if.h"
#include "usb.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

static uint8_t usb_received = 0;
static uint8_t usb_brightness = 100;
static uint8_t usb_report[] = {
	//Bits: [XXXXXXXX][YYYYYYYY][BUTTON_1][BUTTON_2][0][0][0][0][0][0][BBBBBBBB]
	0, 0, 0b00000000, 0
};
void USB_Store_Button(uint8_t button, uint8_t state){
	if(state){
		usb_report[2] |= 1 << button;
	}else{
		usb_report[2] &= ~(1 << button);
	}
}
void USB_Interrupt(uint8_t *data){
	if(!usb_received){
		usb_brightness = data[0];
		usb_received = 1;
	}
}

uint8_t USB_Received(){
	return usb_received;
}
uint8_t USB_Read_Brightness(){
	uint8_t ret = usb_brightness;
	if(ret > 100){
		ret = 100;
	}
	usb_received = 0;
	return ret;
}
void USB_Send(int8_t x, int8_t y, uint8_t button_1, uint8_t button_2, uint8_t backlight){
	usb_report[0] = *(uint8_t *)&x;
	usb_report[1] = *(uint8_t *)&y;
	USB_Store_Button(0, button_1);
	USB_Store_Button(1, button_2);
	usb_report[3] = backlight;
	USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, usb_report, sizeof(usb_report));
}