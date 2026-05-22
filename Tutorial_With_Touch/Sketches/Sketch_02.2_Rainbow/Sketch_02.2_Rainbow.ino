/*
* @ File:   Sketch_02.2_PWM_RGB.ino
* @ Author: [Eason Shen]
* @ Date:   [2026-05-14]
*/
#include "Freenove_WS2812_Lib_for_ESP32.h"

#define FNK0104AB_2P8_240x320_ILI9341
//#define FNK0104N_3P5_320x480_ST77922
//#define FNK0104S_4P0_320x480_ST7796

#ifdef FNK0104N_3P5_320x480_ST77922
 #define LEDS_PIN   40
#else
 #define LEDS_PIN   42
#endif
#define LEDS_COUNT 1
#define CHANNEL    0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

void setup() {
  strip.begin();
  strip.setBrightness(20);  
}

void loop() {
  for (int j = 0; j < 255; j += 1) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 256 / LEDS_COUNT + j) & 255));
    }
    strip.show();
    delay(15);
  }
}
