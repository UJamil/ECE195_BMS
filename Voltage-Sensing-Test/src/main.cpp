#include <mbed.h>

int main()
{

  // put your setup code here, to run once:
  AnalogIn Battery1_VBatt(A0); //
  AnalogIn Battery2_VBatt(A1); //
  AnalogIn Battery3_VBatt(A2); //

  // To be assigned
  AnalogIn Battery1_VShunt(A3); 
  AnalogIn Battery2_VShunt(A4);
  AnalogIn Battery3_VShunt(A5);

  // AnalogIn Battery1_Temp(A6);
  // AnalogIn Battery2_Temp(A7);
  // AnalogIn Battery3_Temp(A8);


  while (1)
  {
    // print the percentage and 16 bit normalized values
    // Voltage
    float B_1_V = 25.386f * (Battery1_VBatt.read() * 3.3f) - 5.2756f;
    float B_2_V = 25.386f * (Battery2_VBatt.read() * 3.3f) - 5.2756f;
    float B_3_V = 25.386f * (Battery3_VBatt.read() * 3.3f) - 5.2756f;
    // Current
    // float B_1_A = ((Battery1_VShunt.read() * 3.3f) -2.5039f) * 200;
    // float B_2_A = ((Battery2_VShunt.read() * 3.3f) -2.5039f) * 200;
    // float B_3_A = ((Battery3_VShunt.read() * 3.3f) -2.5039f) * 200;



    printf("Batt 1 V: %3.4f V\tsBatt 2 V: %3.4f V\tBatt 3 V: %3.4f V\n", B_1_V, B_2_V, B_3_V);
    // printf("Batt 1 A: %3.4f V\tBatt 2 A: %3.4f V\tBatt 3 A: %3.4f V\n", B_1_A, B_2_A, B_3_A);

    // printf("percentage: %3.9f%%\n", ain.read() * 100.0f);
    // printf("normalized: 0x%04X \n", ain.read_u16());

    wait(0.1f); //wait 0.1ms, corresponding to 10kHz
  }
}