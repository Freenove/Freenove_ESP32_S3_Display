/*
* @ File:   Sketch_04.1_Button_Interrupt_UART.ino
* @ Author: [Zhentao Lin]
* @ Date:   [2025-08-19]
*/

#include <Arduino.h>

#define KEY_PIN 0
volatile int interruptCounter = 0;
int lastValue = 0;
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void buttonInit(void) {
  pinMode(KEY_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(KEY_PIN), handleInterrupt, FALLING);
}

void delayDebounce(unsigned int delayTime) {
  unsigned int i = delayTime;
  while (--i > 0) {
    if (digitalRead(KEY_PIN) == HIGH) {
      return;
    }
  }
}

void handleInterrupt(void) {
  portENTER_CRITICAL_ISR(&mux);
  interruptCounter++;
  delayDebounce(20);
  portEXIT_CRITICAL_ISR(&mux);
}

void setup() {
  Serial.begin(115200);
  while(!Serial);
  buttonInit();
  Serial.println("ESP32-S3 initialization completed!");
}

void loop() {
  if (interruptCounter != lastValue) {
    Serial.printf("interruptCounter: %d\r\n", interruptCounter);
    lastValue = interruptCounter;
  }
}
