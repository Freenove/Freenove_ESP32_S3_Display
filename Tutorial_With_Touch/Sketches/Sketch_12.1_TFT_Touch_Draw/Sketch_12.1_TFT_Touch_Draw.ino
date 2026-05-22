/*
* @ File:   Sketch_12.1_TFT_Touch_Draw.ino
* @ Author: [Eason Shen]
* @ Date:   [2026-05-15]
*/

#include <Arduino.h>
#include <TFT_eSPI.h>           // TFT display library

#ifdef FNK0104N_3P5_320x480_ST77922
  #include "ST77922.h"
  #include "ST77922_Touch.h"
  
  TFT_eSPI tft_qspi = TFT_eSPI(); // Invoke custom library
  TFT_eSprite tft = TFT_eSprite(&tft_qspi);
  ST77922 tft_st77922 = ST77922();
  ST77922_TOUCH touch_st77922;

  void flushScreen() {
      tft_st77922.Fill_Colors(0, 0, tft_st77922.Get_Width(), tft_st77922.Get_Height(), (uint16_t *)tft.getPointer());
  }
#else
  #include "FT6336U.h"

  // Invoke custom TFT driver library
  TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

  #define I2C_SDA 16
  #define I2C_SCL 15
  #define RST_N_PIN 18
  #define INT_N_PIN 17

  /* Create an instance of the touch screen library */
  FT6336U ft6336u(I2C_SDA, I2C_SCL, RST_N_PIN, INT_N_PIN); 
  FT6336U_TouchPointType tp; 
  
#endif

#ifdef FNK0104N_3P5_320x480_ST77922
  #define SCREEN_WIDTH 320
  #define SCREEN_HEIGHT 480

  const uint8_t ColorPalette = 30;     // Height of the color palette area
  const uint8_t LineSize = 5;          // Line thickness (radius)
#elif defined FNK0104AB_2P8_240x320_ILI9341
  #define SCREEN_WIDTH 240
  #define SCREEN_HEIGHT 320

  const uint8_t ColorPalette = 21;      // Height of the color palette area
  const uint8_t BrushSize = 2;          // Brush thickness (radius)
  const uint8_t LineSize = 5;           // Line thickness (radius)
#elif defined FNK0104S_4P0_320x480_ST7796
  #define SCREEN_WIDTH 320
  #define SCREEN_HEIGHT 480

  const uint8_t ColorPalette = 30;      // Height of the color palette area
  const uint8_t BrushSize = 2;          // Brush thickness (radius)
  const uint8_t LineSize = 5;           // Line thickness (radius)
#endif

const uint8_t color_num = 12;       
int current_color = TFT_WHITE; 

unsigned int colors[color_num] = { 
  TFT_RED, TFT_PINK, TFT_GREEN, TFT_BLUE, TFT_OLIVE, 
  TFT_CYAN, TFT_YELLOW, TFT_WHITE, TFT_MAGENTA, 
  TFT_ORANGE, TFT_BLACK, TFT_SILVER 
};

// Define coordinate variables
uint16_t x, y;
uint16_t last_x = 0, last_y = 0;

void drawUI() {
    for (int i = 0; i < color_num; i++) {
        tft.fillRect(i * ColorPalette, 0, ColorPalette, ColorPalette, colors[i]);
    }
    #ifdef FNK0104N_3P5_320x480_ST77922
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.drawString("CLEAR", (color_num * ColorPalette) + 10, 8, 2);
      tft.drawRect(tft.width() - 40, 5, 20, 20, TFT_WHITE);
      tft.fillRect(tft.width() - 39, 6, 18, 18, current_color);
      tft.drawFastHLine(0, ColorPalette, tft.width(), TFT_DARKGREY);
      flushScreen();
    #elif defined FNK0104AB_2P8_240x320_ILI9341
      // Draw clear screen button
      tft.setCursor(260 , 3, 2);
      tft.setTextColor(TFT_WHITE);
      tft.print("Clear");
      
      // Display current color
      tft.fillRect(300, 5, 12, 12, current_color);
      
      // Add palette border/outline
      tft.drawRect(0, 0, SCREEN_HEIGHT, ColorPalette, TFT_WHITE);
    #elif defined FNK0104S_4P0_320x480_ST7796
      // Draw clear screen button
      tft.setCursor((color_num * ColorPalette) + 10 , 8, 2);
      tft.setTextColor(TFT_WHITE);
      tft.print("Clear");
      
      // Display current color
      tft.fillRect(tft.width() - 39, 6, 18, 18, current_color);
      tft.drawFastHLine(0, ColorPalette, tft.width(), TFT_DARKGREY);
      
      // Add palette border/outline
      tft.drawRect(tft.width() - 40, 5, 20, 20, TFT_WHITE);
    #endif
}

void setup() {
    Serial.begin(115200);
    #ifdef FNK0104N_3P5_320x480_ST77922
      tft_st77922.Init();
      // Set the TFT and touch screen to landscape orientation
      tft_st77922.Set_Rotation(1);
  
      tft.createSprite(tft_st77922.Get_Width(), tft_st77922.Get_Height());
      tft.setSwapBytes(true);
      tft.fillSprite(TFT_BLACK);
  
      touch_st77922.init();
      touch_st77922.Set_Rotation(1); 
    #else
      ft6336u.begin(); 
      Serial.print("FT6336U Firmware Version: "); 
      Serial.println(ft6336u.read_firmware_id());  
      Serial.print("FT6336U Device Mode: "); 
      Serial.println(ft6336u.read_device_mode());  
      tft.init();
    
      // Set the TFT and touch screen to landscape orientation
      tft.setRotation(1);
    
      tft.fillScreen(TFT_BLACK);
    #endif
    drawUI();
}

void loop() {
    // Check if the touch screen is currently pressed
    // Raw and coordinate values are stored within library at this instant
    // for later retrieval by GetRaw and GetCoord functions.
    #ifdef FNK0104N_3P5_320x480_ST77922
      if (touch_st77922.Get_Touch()) 
      {
        // Read the current X and Y axis as co-ordinates at the last touch time
        x = touch_st77922.touch.x[0];
        y = touch_st77922.touch.y[0];
    #else
      tp = ft6336u.scan(); 
      if (tp.touch_count!=0) // Note this function updates coordinates stored within library variables
      {
        // Read the current X and Y axis as co-ordinates at the last touch time
        // The values were captured when Pressed() was called!
        x = tp.tp[0].y;
        #ifdef FNK0104S_4P0_320x480_ST7796
          y = 320-tp.tp[0].x;
        #elif defined FNK0104AB_2P8_240x320_ILI9341
          y = 240-tp.tp[0].x;
        #endif
        Serial.print(x); Serial.print(","); Serial.println(y);
    #endif
        /* Color palette area logic */
        if (y < ColorPalette + 3) {
            // Enter color selection area, stroke interrupted
            last_x = 0; 
            last_y = 0;
            /* Determine stylus click area */
            // Clicked color palette
            if (x >= color_num * ColorPalette) {
                
              tft.fillRect(0, ColorPalette + 1, tft.width(), tft.height() - ColorPalette - 1, current_color);
              #ifdef FNK0104N_3P5_320x480_ST77922
                flushScreen();
              #endif
            } 
            // Clicked Clear button
            else {
              current_color = colors[x / ColorPalette];
              
              tft.fillRect(tft.width() - 39, 6, 18, 18, current_color);
              #ifdef FNK0104N_3P5_320x480_ST77922
                flushScreen();
              #endif
            }
            return; 
        }

        if (last_x == 0 && last_y == 0) {
            // Record current position
            last_x = x;
            last_y = y;
        }
        
        tft.drawWideLine(last_x, last_y, x, y, LineSize, current_color, current_color);
        #ifdef FNK0104N_3P5_320x480_ST77922
          flushScreen();
        #endif
        
        // Update coordinates
        last_x = x;
        last_y = y;
    } 
    else {
        // Reset coordinates when stylus leaves the screen
        last_x = 0;
        last_y = 0;
    }
}
