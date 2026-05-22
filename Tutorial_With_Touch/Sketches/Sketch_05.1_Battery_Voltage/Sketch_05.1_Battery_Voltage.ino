/*
* @ File:   Sketch_05.1_Battery_Voltage.ino
* @ Author: [Eason Shen]
* @ Date:   [2026-05-15]
*/

#define FNK0104AB_2P8_240x320_ILI9341
//#define FNK0104N_3P5_320x480_ST77922
//#define FNK0104S_4P0_320x480_ST7796

#ifdef FNK0104N_3P5_320x480_ST77922
 #define BAT_ADC_PIN  8
#else
 #define BAT_ADC_PIN  9
#endif

void setup(){
  Serial.begin(115200);
  pinMode(BAT_ADC_PIN, INPUT);
}

void loop() {
  int adcValue= analogRead(BAT_ADC_PIN);
  float batteryVoltage = analogReadMilliVolts(BAT_ADC_PIN) * 2.0 / 1000;
  Serial.printf("Reading on Pin(%d), adcValue=%d, batteryVoltage2=%fV\n", BAT_ADC_PIN, adcValue, batteryVoltage);
  delay(300);
}
