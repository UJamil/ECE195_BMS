/*
    Filename: main.cpp
    Author: Usman J.
    Purpose: Firmware for Battery Monitoring System, 
        designed and developed for Outback Power
    Description:
    Notes: Communication over SPI with the Maxim MAX1228 12-bit 10-channel ADC
    Credits: Developed using ARM mbed platform: https://os.mbed.com/
*/
#include "mbed.h"

#define NUM_CHANNELS 9
#define RX_BUFFER_SIZE 4
#define MESSAGE_INIT 0x80

// Function prototypes
void setupADC(SPI);                     // Setup and initialize SPI communication for ADC
void print_ADC_value(char *, int, int); // Console print hex values from ADC, for debugging
float extract_float(char *);
// Declare SPI object globally
SPI maximADC(PA_7, PA_6, PA_5, PA_4); // mosi, miso, sclk, ssel

int main()
{
  setupADC(maximADC);

  char conv_req = MESSAGE_INIT;
  char adc_response[RX_BUFFER_SIZE];
  float channel_value[NUM_CHANNELS];

  while (1)
  {
    maximADC.lock();
    for (int i = 0; i < NUM_CHANNELS; i++) // Iterate through each ADC Channel
    {
      maximADC.write(&conv_req, 2, adc_response, RX_BUFFER_SIZE);
      float adc_value_f = (extract_float(adc_response)) / 1000;
      channel_value[i] = adc_value_f;

      printf("%f", adc_value_f);
      printf("\n");

      conv_req += 0x08; // increment to next channel
    }

    for (int j = 0; j < NUM_CHANNELS; j += 3) // Voltage Format
    {
      25.386f * channel_value[j] - 5.2756f;
    }
    for (int k = 1; k < NUM_CHANNELS; k += 3) // Current Format
    {
      (channel_value[j] - 2.5039f) * 200;
    }
    for (int l = 2; l < NUM_CHANNELS; l += 3) // Temperature Format
    {
      channel_value[j]; // TODO: Change
    }

    maximADC.unlock();
    conv_req = MESSAGE_INIT; // Reset to channel 0
    wait_ms(1000);
  }
}

void setupADC(SPI maximADC)
{
  maximADC.lock();
  maximADC.format(8, 0);       // 8-bit frame, pol = phase
  maximADC.frequency(1000000); // 1MHz clock frequency, looks unstable if lower?
  //maximADC.write(0x10);        // Reset
  //maximADC.write(0x00);        // Buffer

  maximADC.write(0x76); // select setup register, external timing (CNVST), internal reference off (external single ended 5V), unipolar setup
  maximADC.write(0x00); // set all ADC channels to unipolar single-ended
  maximADC.unlock();
}

void print_ADC_value(char *adc_response, int size, int ch) // for debugging, print    hex values
{
  printf("ch%d: ", ch);
  for (int i = 0; i < size; i++)
    printf("%d", adc_response[i]);
  printf("\n");
  return;
}

float extract_float(char *input)
{
  uint16_t adc_value = ((char)input[2] + ((char)input[1] << 8));
  float adc_value_f = 1.2 * adc_value;
  return adc_value_f;
}