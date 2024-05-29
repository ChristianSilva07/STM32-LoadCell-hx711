// HX711/LoadCell Simple Code for STM32 (NO LIBRARY)

// Select 2 pins on CubeMX for clock (CLK output push-pull) and data (DAT input no pull-up and no pull-down).

![Screenshot 2024-05-28 211541](https://github.com/ChristianSilva07/STM32-LoadCell-hx711/assets/79029711/d042cde6-d11b-454a-a49e-05aa0c30ca1b)

// Configure the code in main.c. (Don't forget to DEFINE DOUT and SCK as the pins you selected in CubeMx)

![Screenshot 2024-05-28 214150](https://github.com/ChristianSilva07/STM32-LoadCell-hx711/assets/79029711/c91c42f8-e4fd-4f40-ad1b-c4be2a8b8813)

// Call hx711_init() in your AppTask.

![Screenshot 2024-05-28 214249](https://github.com/ChristianSilva07/STM32-LoadCell-hx711/assets/79029711/277fc829-e7d2-42ee-a8cf-da6db253e137)

// After initialization, you can read the value with (hx711Data = HX711_Read();) in your IOTask; (using Live Watch Variable)

![Screenshot 2024-05-28 214253](https://github.com/ChristianSilva07/STM32-LoadCell-hx711/assets/79029711/23e5261d-c024-4bb0-bcf2-570a722b35ac)

// The LoadCell via HX711 is working with No Library in STM32.
