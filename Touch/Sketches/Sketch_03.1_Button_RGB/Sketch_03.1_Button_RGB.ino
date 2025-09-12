/*
* @ File:   Sketch_03.1_Button_RGB.ino
* @ Author: [Zhentao Lin]
* @ Date:   [2025-08-19]
*/

#include <Arduino.h>
#include "Freenove_WS2812_Lib_for_ESP32.h"

#define KEY_PIN 0
#define LEDS_COUNT 1
#define LEDS_PIN   42
#define CHANNEL    0

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(LEDS_COUNT, LEDS_PIN, CHANNEL, TYPE_GRB);

uint8_t m_color[5][3] = { { 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 }, { 255, 255, 255 }, { 0, 0, 0 } };

static unsigned int keyCount = 0;
static unsigned int lastKeyCount = 1;

void buttonInit(void) {
  pinMode(KEY_PIN, INPUT_PULLUP);
}

bool readButton(void) {
  return digitalRead(KEY_PIN);
}

void switchRGB(int value) {
  int colorIndex = value % 4;
  switch (colorIndex) {
    case 1:
      strip.setLedColorData(0, m_color[0][0], m_color[0][1], m_color[0][2]);
      strip.show();
      break;
    case 2:
      strip.setLedColorData(0, m_color[1][0], m_color[1][1], m_color[1][2]);
      strip.show();
      break;
    case 3:
      strip.setLedColorData(0, m_color[2][0], m_color[2][1], m_color[2][2]);
      strip.show();
      break;
    default:
      strip.setLedColorData(0, m_color[4][0], m_color[4][1], m_color[4][2]);
      strip.show();
      break;
  }
}

void setup() {
  strip.begin();
  strip.setBrightness(10);
  buttonInit();
  Serial.println("ESP32-S3 initialization completed!");
}

void loop() {
  if (readButton() == 0) {
    delay(20);
    if (readButton() == 0) {
      keyCount++;
      while (!readButton());
    }
  }
  if (keyCount != lastKeyCount) {
    switchRGB(keyCount);
    lastKeyCount = keyCount;
  }
}
