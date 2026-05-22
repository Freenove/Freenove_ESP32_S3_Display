/*
* @ File:   Sketch_10.2_Flash_Jpg.ino
* @ Author: [Eason Shen]
* @ Date:   [2026-05-15]
*/
// Example for library: https://github.com/Bodmer/TJpg_Decoder

// This example renders a JPEG file stored in Flash memory (see panda.h)

#include <TFT_eSPI.h>  // TFT display library
#include <SPI.h>
#include "panda.h"         // Include raw JPEG image data array
#include <TJpg_Decoder.h>  // Include JPEG decoder library

#ifdef FNK0104N_3P5_320x480_ST77922
  TFT_eSPI tft_qspi = TFT_eSPI();
  TFT_eSprite tft = TFT_eSprite(&tft_qspi);
  ST77922 tft_st77922 = ST77922();
#else
  TFT_eSPI tft = TFT_eSPI();  // Create TFT object instance
#endif

// Callback function to draw decoded JPEG blocks on screen
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap) {
  if (y >= tft.height()) return 0;  // Stop decoding if off-screen
  tft.pushImage(x, y, w, h, bitmap);  // Draw without DMA
  #ifdef FNK0104N_3P5_320x480_ST77922
    tft_st77922.Fill_Colors(0, 0, tft_st77922.Get_Width(), tft_st77922.Get_Height(), (uint16_t *)tft.getPointer());
  #endif
  return 1;  // Continue decoding next block
}

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n Testing TJpg_Decoder library");
  #ifdef FNK0104N_3P5_320x480_ST77922
    tft_st77922.Init();
    tft_st77922.Set_Rotation(0);
    tft.createSprite(tft_st77922.Get_Width(), tft_st77922.Get_Height());
    tft.setSwapBytes(1);
    tft.fillSprite(TFT_BLACK);
    tft_st77922.Fill_Colors(0, 0, tft_st77922.Get_Width(), tft_st77922.Get_Height(), (uint16_t *)tft.getPointer());
  #else
    tft.begin();
    tft.fillScreen(TFT_BLACK);
  #endif
  TJpgDec.setJpgScale(1);           // Set scale factor (1=full size)
  tft.setSwapBytes(true);           // Match color byte order
  TJpgDec.setCallback(tft_output);  // Register drawing callback
}

void loop() {
  uint16_t w = 0, h = 0;
  TJpgDec.getJpgSize(&w, &h, img_asset, sizeof(img_asset));  // Get image dimensions
  Serial.print("Width = ");
  Serial.print(w);
  Serial.print(", height = ");
  Serial.print(h);

  uint32_t dt = millis();
  tft.startWrite();
  TJpgDec.drawJpg(0, 0, img_asset, sizeof(img_asset));  // Draw the JPEG image
  tft.endWrite();

  dt = millis() - dt;
  Serial.print(", dt = ");
  Serial.print(dt);
  Serial.println(" ms");

  delay(2000);  // Wait before redraw
}
