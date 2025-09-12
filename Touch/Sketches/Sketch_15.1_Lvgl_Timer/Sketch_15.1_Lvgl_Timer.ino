/*
* @ File:   Sketch_15.1_LVGL_Timer.ino
* @ Author: [Zhentao Lin]
* @ Date:   [2025-06-23]
*/

#include "display.h"
#include "chronograph_ui.h"

Display screen;
void setup() {
  Serial.begin(115200);

  /*** Init screen ***/
  screen.init();

  /***  Print lvgl version ***/
  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.println(LVGL_Arduino);
  Serial.println("I am LVGL_Arduino");
  Serial.println("Setup done");

  /*** The custom code ***/
  setup_scr_chronograph(&guider_chronograph_ui);
  lv_scr_load(guider_chronograph_ui.chronograph);
}

void loop() {
  screen.routine();
  delay(1);
}