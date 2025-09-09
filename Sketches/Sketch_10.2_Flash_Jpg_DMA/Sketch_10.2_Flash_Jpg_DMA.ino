// Example for library: https://github.com/Bodmer/TJpg_Decoder

// This example renders a JPEG file stored in Flash memory (see panda.h)

#include <TFT_eSPI.h>  // TFT display library
#include "panda.h"         // Include raw JPEG image data array
#include <TJpg_Decoder.h>  // Include JPEG decoder library

TFT_eSPI tft = TFT_eSPI();  // Create TFT object instance

// Callback function to draw decoded JPEG blocks on screen
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap) {
  if (y >= tft.height()) return 0;  // Stop decoding if off-screen
  tft.pushImage(x, y, w, h, bitmap);  // Draw without DMA
  return 1;  // Continue decoding next block
}

void setup() {
  Serial.begin(115200);
  Serial.println("\n\n Testing TJpg_Decoder library");

  tft.begin();  // Initialize TFT display
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.fillScreen(TFT_BLACK);  // Clear screen with black background
  tft.setRotation(0);

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