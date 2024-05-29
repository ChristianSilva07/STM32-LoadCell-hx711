/* USER CODE BEGIN PV */

// set your pin here
#define HX711_DOUT_PIN GPIO_PIN_8 
#define HX711_DOUT_PORT GPIOB
#define HX711_SCK_PIN GPIO_PIN_9
#define HX711_SCK_PORT GPIOB

/* USER CODE END PV */

/* USER CODE BEGIN 0 */
void HX711_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
  
	__HAL_RCC_GPIOA_CLK_ENABLE(); // Enable the Clock of the Port GPIO
  
	// DOUT with pull-up (set on MXCUBE)
	GPIO_InitStruct.Pin = HX711_DOUT_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(HX711_DOUT_PORT, &GPIO_InitStruct);
  
	// SCK with output push-pull (set on MXCUBE)
	GPIO_InitStruct.Pin = HX711_SCK_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(HX711_SCK_PORT, &GPIO_InitStruct);
}

uint32_t HX711_Read(void) {
	uint32_t data = 0;

    // wait dout is be low
	while (HAL_GPIO_ReadPin(HX711_DOUT_PORT, HX711_DOUT_PIN) == GPIO_PIN_SET) ;

    // read of the 24 bits

	for (int i = 0; i < 24; i++) {
		HAL_GPIO_WritePin(HX711_SCK_PORT, HX711_SCK_PIN, GPIO_PIN_SET);
		data = (data << 1) | HAL_GPIO_ReadPin(HX711_DOUT_PORT, HX711_DOUT_PIN);
		HAL_GPIO_WritePin(HX711_SCK_PORT, HX711_SCK_PIN, GPIO_PIN_RESET);
	}

    // one more pulse to complete the reading

	HAL_GPIO_WritePin(HX711_SCK_PORT, HX711_SCK_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(HX711_SCK_PORT, HX711_SCK_PIN, GPIO_PIN_RESET);

	// 
Adjust sign to 24-bit number
	if (data & 0x800000) {
		data |= 0xFF000000; // Fill sign bits for negative numbers
	}

	return data;
}

uint32_t hx711Data; // variable for reading


/* USER CODE END 0 */

  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
	  HX711_Init(); // init the hx711 reading
  }
  /* USER CODE END 5 */

  /* USER CODE BEGIN StartIOTask */
  /* Infinite loop */
  for(;;)
{
    osDelay(1);

	  //read loadcell/hx7711
	  hx711Data = HX711_Read(); // the hx711//Loadcell is reading right her
}
  /* USER CODE END StartIOTask */