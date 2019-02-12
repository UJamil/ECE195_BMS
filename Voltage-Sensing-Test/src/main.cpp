#include <mbed.h>

int main()
{

  // put your setup code here, to run once:
  AnalogIn Battery1_VBatt(A0); //
  AnalogIn Battery2_VBatt(A1); //
  AnalogIn Battery3_VBatt(A2); //

  // To be assigned
  // AnalogIn Battery1_VShunt(A3); 
  // AnalogIn Battery2_VShunt(A4);
  // AnalogIn Battery3_VShunt(A5);

  // AnalogIn Battery1_Temp(A6);
  // AnalogIn Battery2_Temp(A7);
  // AnalogIn Battery3_Temp(A8);


  while (1)
  {
    // print the percentage and 16 bit normalized values
    printf("Batt 1 V: %3.4f V\tBatt 2 V: %3.4f V\tBatt 3 V: %3.4f V\n", Battery1_VBatt.read() * 3.3f, Battery2_VBatt.read() * 3.3f, Battery3_VBatt.read() * 3.3f);
    // printf("percentage: %3.9f%%\n", ain.read() * 100.0f);
    // printf("normalized: 0x%04X \n", ain.read_u16());

    wait(0.1f); //wait 0.1ms, corresponding to 10kHz
  }
}