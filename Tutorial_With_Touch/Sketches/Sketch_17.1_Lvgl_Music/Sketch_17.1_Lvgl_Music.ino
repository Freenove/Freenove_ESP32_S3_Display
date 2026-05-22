/*
* @ File:   Sketch_17.1_LVGL_RGB.ino
* @ Author: [Zhentao Lin]
* @ Date:   [2025-06-23]
*/

#include <Arduino.h>
#include "Wire.h"
#include "display.h"
#include "driver_sdmmc.h"
#include "music_ui.h"
#include "es8311.h"
#include "ESP_I2S.h"

#ifdef FNK0104N_3P5_320x480_ST77922
#define SD_MMC_CLK 5
#define SD_MMC_CMD 4
#define SD_MMC_D0 6
#define SD_MMC_D1 7
#define SD_MMC_D2 2
#define SD_MMC_D3 3

//I2S IO Pin define
#define I2S_MCK 17
#define I2S_BCK 18
#define I2S_DINT 16
#define I2S_DOUT 15
#define I2S_WS 21
#define AP_ENABLE 1
#define I2C_SCL 39        /*!< GPIO number used for I2C master clock */
#define I2C_SDA 38        /*!< GPIO number used for I2C master data  */
#define I2C_SPEED 400000  /*!< I2C master clock frequency */

#else
#define SD_MMC_CMD 40  // Please do not modify it.
#define SD_MMC_CLK 38  // Please do not modify it.
#define SD_MMC_D0  39  // Please do not modify it.
#define SD_MMC_D1  41  // Please do not modify it.
#define SD_MMC_D2  48  // Please do not modify it.
#define SD_MMC_D3  47  // Please do not modify it.

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
#endif

Display screen;
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

void setup(){
    /* prepare for possible serial debug */
    Serial.begin( 115200 );

   /*** Init drivers ***/
    sdmmc_init(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0, SD_MMC_D1, SD_MMC_D2, SD_MMC_D3);//Initialize the SD module
    driver_es8311_init();
    if (es8311_codec_init() != ESP_OK) {
      Serial.println("ES8311 init failed!");
      return;
    }
    es8311_set_mic_gain(ES8311_MIC_GAIN_MIN); // Close mic
    screen.init();

    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
    Serial.println( LVGL_Arduino );
    Serial.println( "I am LVGL_Arduino" );
    
    setup_scr_music(&guider_music_ui);
    lv_scr_load(guider_music_ui.music);

    Serial.println( "Setup done" );
}

void loop(){
    screen.routine(); /* let the GUI do its work */
    delay( 5 );
}
