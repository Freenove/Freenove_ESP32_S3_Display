/*
* @ File:   Sketch_10.1_TFT_Rainbow.ino
* @ Author: [Zhentao Lin]
* @ Date:   [2025-08-23]
*/

#include <TFT_eSPI.h>  // TFT display library

TFT_eSPI tft = TFT_eSPI();  // Create TFT object instance

unsigned long targetTime = 0;     // Timing variable to control animation intervals
byte red = 31;                    // Start with full red
byte green = 0;                   // No green
byte blue = 0;                    // No blue
byte state = 0;                   // State machine variable
unsigned int colour = red << 11;  // Initial color value: Red only

void setup(void) {
  tft.init();                   // Initialize the TFT screen
  tft.setRotation(1);           // Set screen rotation (landscape mode)
  targetTime = millis() + 100;  // Set initial target time for rainbow effect
  tft.fillScreen(TFT_RED);  // Fill screen with solid red
  delay(1000);
  tft.fillScreen(TFT_GREEN);  // Fill screen with solid green
  delay(1000);
  tft.fillScreen(TFT_BLUE);  // Fill screen with solid blue
  delay(1000);
  tft.fillScreen(TFT_BLACK);  // Fill screen with solid black
  delay(1000);
  tft.fillScreen(TFT_WHITE);  // Fill screen with solid white
  delay(1000);
}

void loop() {
  if (targetTime < millis()) {      // Check if it's time to start the rainbow animation
    targetTime = millis() + 10000;  // Set next trigger after 10 seconds

    for (int i = 0; i < 320; i++) {                   // Generate horizontal rainbow using vertical lines
      tft.drawFastVLine(i, 0, tft.height(), colour);  // Draw one vertical line
      switch (state) {
        case 0:
          green += 2;  // Transition from red to yellow (increase green)
          if (green == 64) {
            green = 63;  // Cap at max green value
            state = 1;
          }
          break;
        case 1:
          red--;  // Transition from yellow to green (decrease red)
          if (red == 255) {
            red = 0;
            state = 2;
          }
          break;
        case 2:
          blue++;  // Transition from green to cyan (increase blue)
          if (blue == 32) {
            blue = 31;  // Cap at max blue value
            state = 3;
          }
          break;
        case 3:
          green -= 2;  // Transition from cyan to blue (decrease green)
          if (green == 255) {
            green = 0;
            state = 4;
          }
          break;
        case 4:
          red++;  // Transition from blue to magenta (increase red)
          if (red == 32) {
            red = 31;  // Cap at max red value
            state = 5;
          }
          break;
        case 5:
          blue--;  // Transition from magenta to red (decrease blue)
          if (blue == 255) {
            blue = 0;
            state = 0;
          }
          break;
      }
      colour = red << 11 | green << 5 | blue;  // Combine RGB values into 16-bit color
    }
    tft.setTextColor(TFT_BLACK);           // Set text color to black
    tft.setCursor(12, 5);                  // Set cursor position
    tft.print("Original ADAfruit font!");  // Print simple string
    tft.setTextColor(TFT_BLACK, TFT_BLACK);  // Transparent background
    tft.drawCentreString("Font size 2", 80, 14, 2);              // Font 2
    tft.drawCentreString("Font size 4", 80, 30, 4);              // Font 4
    tft.drawCentreString("12.34", 80, 54, 6);                    // Font 6
    tft.drawCentreString("12.34 is in font size 6", 80, 92, 2);  // Font 2
    float pi = 3.14159;                                      // Value to print
    int precision = 3;                                       // Number of decimal digits
    int xpos = 50;                                           // X position
    int ypos = 110;                                          // Y position
    int font = 2;                                            // Font type
    xpos += tft.drawFloat(pi, precision, xpos, ypos, font);  // Draw float and update x-position
    tft.drawString(" is pi", xpos, ypos, font);              // Continue drawing string from updated x position
    delay(6000);  // Wait before next cycle
  }
}