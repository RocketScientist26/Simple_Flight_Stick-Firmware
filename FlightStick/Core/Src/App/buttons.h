#define BUTTON_DEBOUNCE_SAMPLES 10

void Buttons_Interrupt(uint16_t GPIO_Pin);
uint8_t Buttons_Debounce_Read(GPIO_TypeDef  *GPIOx, uint16_t GPIO_Pin);
uint8_t Buttons_Pressed(uint16_t GPIO_Pin);
uint8_t Buttons_Read(uint16_t GPIO_Pin);