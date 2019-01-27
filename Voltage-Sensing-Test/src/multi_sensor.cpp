#include <mbed.h>
#include <TARGET_STM32F429xI/device/system_stm32f4xx.h>
#include <TARGET_STM32F429xI/device/stm32f429xx.h>
#include <stm32f439xx.h>
#include <TARGET_STM32F429xI/TARGET_NUCLEO_F429ZI/PeripheralNames.h>
#include <TARGET_STM32F429xI/TARGET_NUCLEO_F429ZI/PinNames.h>

int main()
{

  // put your setup code here, to run once:
  AnalogIn ain(A0);
  DigitalOut dout(LED1);
  while (1)
  {
    //test the voltage on the initialized analog pin
    //  and if greater than 0.5 * VCC set1the digital pin
    //  to a logic 1 otherwise a logic 0
    if (ain > 0.5f)
    {
      dout = 1;
    }
    else
    {
      dout = 0;
    }

    // print the percentage and 16 bit normalized values
    printf ("voltage: %3.9f\n", ain.read() * 3.3f);

    // printf("percentage: %3.9f%%\n", ain.read() * 100.0f);
    // printf("normalized: 0x%04X \n", ain.read_u16());

    // wait(0.1f);
  }
}