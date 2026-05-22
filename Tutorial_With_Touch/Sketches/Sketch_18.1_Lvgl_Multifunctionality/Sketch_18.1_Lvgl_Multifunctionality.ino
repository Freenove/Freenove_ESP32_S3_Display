/*
* @ File:   Sketch_18.1_Lvgl_Multifunctionality.ino
* @ Author: [Zhentao Lin]
* @ Date:   [2025-06-23]
*/

#include "public.h"

Display screen;
I2SClass es8311_i2s;
void fix_image_color_u8(uint8_t * data, uint32_t len_bytes) {
    for(uint32_t i = 0; i < len_bytes; i += 2) {
        uint8_t temp = data[i];
        data[i] = data[i+1];
        data[i+1] = temp;
    }
}
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
  /* prepare for possible serial debug */
  Serial.begin(115200);
  #ifdef FNK0104N_3P5_320x480_ST77922
    fix_image_color_u8(img_freenove_map, 160 * 90 * 2); 
  #endif
  /*** Init drivers ***/
  sdmmc_init(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0, SD_MMC_D1, SD_MMC_D2, SD_MMC_D3);  //Initialize the SD module
  driver_es8311_init();
  if (es8311_codec_init() != ESP_OK) {
    Serial.println("ES8311 init failed!");
    return;
  }
  screen.init();

  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.println(LVGL_Arduino);
  Serial.println("I am LVGL_Arduino");

  setup_scr_main(&guider_main_ui);
  lv_scr_load(guider_main_ui.main);

  Serial.println("Setup done");
}

void loop() {
  screen.routine(); /* let the GUI do its work */
  delay(5);
}
