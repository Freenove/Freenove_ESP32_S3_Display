#include <Arduino.h>
#include "FS.h"
#include "SD_MMC.h"
#include "SPI.h"
#include "es8311.h"
#include "Audio.h"
#include "Wire.h"
#include "ESP_I2S.h"
#include "demo_music.h"

//ESP32-S3 IO Pin define
#define SD_SCK 38
#define SD_CMD 40
#define SD_D0 39
#define SD_D1 41
#define SD_D2 48
#define SD_D3 47

//I2S IO Pin define
#define I2S_MCK 4
#define I2S_BCK 5
#define I2S_DINT 6
#define I2S_DOUT 8
#define I2S_WS 7
#define AP_ENABLE 1
#define I2C_SCL 15        /*!< GPIO number used for I2C master clock */
#define I2C_SDA 16        /*!< GPIO number used for I2C master data  */
#define I2C_SPEED 400000  /*!< I2C master clock frequency */

Audio audio;
I2SClass es8311_i2s;

void driver_es8311_init(void) {
  pinMode(AP_ENABLE, OUTPUT);
  digitalWrite(AP_ENABLE, LOW);

  Wire.begin(I2C_SDA, I2C_SCL, I2C_SPEED);

  es8311_i2s.setPins(I2S_BCK, I2S_WS, I2S_DOUT, I2S_DINT, I2S_MCK);
  if (!es8311_i2s.begin(I2S_MODE_STD, 44100, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO, I2S_STD_SLOT_LEFT)) {
    Serial.println("Failed to initialize I2S bus!");
  }
}

void setup() {
  Serial.begin(115200);

  //SD card init
  if (!SD_MMC.setPins(SD_SCK, SD_CMD, SD_D0, SD_D1, SD_D2, SD_D3)) {
    Serial.println("Pin change failed!");
    return;
  }
  while (!SD_MMC.begin()) {
    Serial.println("SD card does not exist,please insert SD card.");
    delay(100);
  }

  driver_es8311_init();
  if (es8311_codec_init() != ESP_OK) {
    Serial.println("ES8311 init failed!");
    return;
  }
  //audio init
  audio.setPinout(I2S_BCK, I2S_WS, I2S_DOUT, I2S_MCK);
  audio.setVolume(10);
  if (!demo_music()) {
    return;
  }

  //play music
  demo_music_play(1);
}

void loop() {
  audio.loop();
}