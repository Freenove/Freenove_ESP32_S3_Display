#ifndef __PUBLIC_H
#define __PUBLIC_H

#include <Arduino.h>
#include "lvgl.h"
#include "stdlib.h"
#include "string.h"
#include "Wire.h"
#include "es8311.h"
#include "ESP_I2S.h"
#include "Audio.h"
#include "display.h"
#include "driver_sdmmc.h"
#include "lv_img.h"

#include "main_ui.h"
#include "music_ui.h"
#include "picture_ui.h"
#include "chronograph_ui.h"
#include "ws2812_ui.h"

//SDMMC IO Pin
#define SD_MMC_CMD 40  // Please do not modify it.
#define SD_MMC_CLK 38  // Please do not modify it.
#define SD_MMC_D0  39  // Please do not modify it.
#define SD_MMC_D1  41  // Please do not modify it.
#define SD_MMC_D2  48  // Please do not modify it.
#define SD_MMC_D3  47  // Please do not modify it.

//I2S IO Pin
#define I2S_MCK 4
#define I2S_BCK 5
#define I2S_DINT 6
#define I2S_DOUT 8
#define I2S_WS 7
#define AP_ENABLE 1
#define I2C_SCL 15        /*!< GPIO number used for I2C master clock */
#define I2C_SDA 16        /*!< GPIO number used for I2C master data  */
#define I2C_SPEED 400000  /*!< I2C master clock frequency */

//WS2812 IO PIN
#define LEDS_COUNT 1
#define LEDS_PIN 42
#define CHANNEL 0




#endif
