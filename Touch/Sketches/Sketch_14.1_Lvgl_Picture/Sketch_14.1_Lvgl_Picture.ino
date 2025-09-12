/**
 * Sketch_14_Lvgl_Picture.ino
 * This sketch demonstrates the use of the LVGL library to display images on a graphical user interface (GUI)
 * on an ESP32 microcontroller. It initializes a display, sets up an SD card for image storage, and loads a specific UI screen using LVGL.
 * The GUI includes elements managed by LVGL, and images are loaded from the SD card for display.
 *
 * Author: Zhentao Lin
 * Date:   2025-04-08
 */
#include "display.h"
#include "picture_ui.h"
#include "driver_sdmmc.h"

#define SD_MMC_CMD 40  // Please do not modify it.
#define SD_MMC_CLK 38  // Please do not modify it.
#define SD_MMC_D0  39  // Please do not modify it.
#define SD_MMC_D1  41  // Please do not modify it.
#define SD_MMC_D2  48  // Please do not modify it.
#define SD_MMC_D3  47  // Please do not modify it.

Display screen;  // Create an instance of the Display class

void setup() {
  /* Prepare for possible serial debug */
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate

  /* Initialize SD card */
  sdmmc_init(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0, SD_MMC_D1, SD_MMC_D2, SD_MMC_D3);
  create_dir(PICTURE_FOLDER);

  /*** Initialize the screen ***/
  screen.init();  // Initialize the display

  // Create a string to display LVGL version information
  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  // Print LVGL version information to the serial monitor
  Serial.println(LVGL_Arduino);
  Serial.println("I am LVGL_Arduino");

  setup_scr_picture(&guider_picture_ui);
  lv_scr_load(guider_picture_ui.picture);

  // Print setup completion message to the serial monitor
  Serial.println("Setup done");
}

void loop() {
  screen.routine(); /* Let the GUI do its work */  // Handle routine display tasks
  delay(5);                                        // Add a small delay to prevent the loop from running too fast
}
