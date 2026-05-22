#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "lvgl.h"
#include "Arduino.h"
#include "TFT_eSPI.h"

#if defined (FNK0104AB_2P8_240x320_ILI9341) || defined (FNK0104S_4P0_320x480_ST7796)
  #define I2C_SCL 15
  #define I2C_SDA 16
  #define INT_N_PIN 17
  #define RST_N_PIN 18
#endif

#define TFT_DIRECTION 0   //TFT direction

class Display
{
private:

public:
    void init();
    void routine();
};

#endif
