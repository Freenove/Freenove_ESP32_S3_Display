/*
* @ File:   Sketch_11_Touch.ino
* @ Author: [Eason Shen]
* @ Date:   [2026-05-15]
*/

#include <Arduino.h>
#include <TFT_eSPI.h>

#ifdef FNK0104N_3P5_320x480_ST77922
  #include "ST77922.h"
  #include "ST77922_Touch.h"
  
  TFT_eSPI tft_qspi = TFT_eSPI();
  TFT_eSprite tft = TFT_eSprite(&tft_qspi);
  ST77922 tft_st77922 = ST77922();
  ST77922_TOUCH touch_st77922;
#else
  #include "FT6336U.h"
  #define I2C_SDA 16
  #define I2C_SCL 15
  #define RST_N_PIN 18
  #define INT_N_PIN 17
  FT6336U ft6336u(I2C_SDA, I2C_SCL, RST_N_PIN, INT_N_PIN); 
  FT6336U_TouchPointType tp; 
#endif

void setup() {
    Serial.begin(115200);

    #ifdef FNK0104N_3P5_320x480_ST77922
      tft_st77922.Init();
      tft_st77922.Set_Rotation(1); 
      tft.createSprite(tft_st77922.Get_Width(), tft_st77922.Get_Height());
      tft.setSwapBytes(true);
      
      tft.fillSprite(TFT_WHITE);  // Fill screen with solid red
      tft.setTextColor(TFT_BLACK);
      tft.setTextDatum(MC_DATUM);
      tft.drawString("ST77922 Touch", tft_st77922.Get_Width()/2, tft_st77922.Get_Height()/2, 4);
      tft_st77922.Fill_Colors(0, 0, tft_st77922.Get_Width(), tft_st77922.Get_Height(), (uint16_t *)tft.getPointer());
  
      touch_st77922.init();
      touch_st77922.Set_Rotation(1); 
    #else
      ft6336u.begin(); 
      Serial.print("FT6336U Firmware Version: "); 
      Serial.println(ft6336u.read_firmware_id());  
      Serial.print("FT6336U Device Mode: "); 
      Serial.println(ft6336u.read_device_mode());  
      Serial.println("ST77922 Touch Initialized.");
    #endif
}

void loop() {
    #ifdef FNK0104N_3P5_320x480_ST77922
      if (touch_st77922.Get_Touch()) {
          Serial.print("ST77922 Touch: ");
          for (int i = 0; i < touch_st77922.max_points; i++) {
              if (touch_st77922.touch.x[i] > 0 || touch_st77922.touch.y[i] > 0) {
                  Serial.printf("[P%d: %4d, %4d] ", i+1, touch_st77922.touch.x[i], touch_st77922.touch.y[i]);
              }
              touch_st77922.touch.x[i] = 0;
              touch_st77922.touch.y[i] = 0;
          }
          Serial.println();
          delay(50);
      }
    #else
      tp = ft6336u.scan();
      char tempString[128];
      sprintf(tempString, "FT6336U TD Count %d / TD1 (%d, %4d, %4d) / TD2 (%d, %4d, %4d)\r\n", tp.touch_count, tp.tp[0].status, tp.tp[0].x, tp.tp[0].y, tp.tp[1].status, tp.tp[1].x, tp.tp[1].y); 
      Serial.print(tempString);
      delay(100);
    #endif
}
