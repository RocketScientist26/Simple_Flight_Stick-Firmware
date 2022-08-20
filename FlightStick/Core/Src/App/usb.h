void USB_Store_Button(uint8_t button, uint8_t state);
void USB_Interrupt(uint8_t *data);
uint8_t USB_Received();
uint8_t USB_Read_Brightness();
void USB_Send(int8_t x, int8_t y, uint8_t button_1, uint8_t button_2, uint8_t backlight);