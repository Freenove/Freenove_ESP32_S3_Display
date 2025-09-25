#include <Arduino.h>
#include "FS.h"
#include "SD_MMC.h"
#include "SPI.h"
#include "es8311.h"
#include "Audio.h"
#include "Wire.h"
#include "ESP_I2S.h"

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
#define I2C_SCL 15       
#define I2C_SDA 16      
#define I2C_SPEED 400000 

I2SClass es8311_i2s;

void driver_es8311_init(void) {
  pinMode(AP_ENABLE, OUTPUT);
  digitalWrite(AP_ENABLE, LOW);

  Wire.begin(I2C_SDA, I2C_SCL, I2C_SPEED);

  es8311_i2s.setPins(I2S_BCK, I2S_WS, I2S_DOUT, I2S_DINT, I2S_MCK);
  if (!es8311_i2s.begin(I2S_MODE_STD, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO, I2S_STD_SLOT_LEFT)) {
    Serial.println("Failed to initialize I2S bus!");
  }
}

void setup()
{
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  Serial.println("Start initializing the audio device...");
  driver_es8311_init();
  if (es8311_codec_init() != ESP_OK) {
    Serial.println("ES8311 init failed!");
    return;
  }
  delay(3000);
  Serial.println("Initialization completed.");
}

void loop()
{
  uint8_t *wav_buffer;
  size_t wav_size;
  // Record 5 seconds of audio data
  Serial.println("Start recording for 5 seconds...");
  wav_buffer = es8311_i2s.recordWAV(5, &wav_size);
  Serial.println("Recording completed.");
  delay(1000);

  Serial.println("Start playing the recording...");
  es8311_i2s.playWAV(wav_buffer, wav_size);
  Serial.println("Playback has been completed.");
  free(wav_buffer);
  delay(1000);
}