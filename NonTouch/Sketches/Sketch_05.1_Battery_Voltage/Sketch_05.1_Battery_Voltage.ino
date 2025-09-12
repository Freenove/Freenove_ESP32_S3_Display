/*
* @ File:   Sketch_05.1_Battery_Voltage.ino
* @ Author: [Zhentao Lin]
* @ Date:   [2025-08-19]
*/

#define BAT_ADC_PIN  9

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
