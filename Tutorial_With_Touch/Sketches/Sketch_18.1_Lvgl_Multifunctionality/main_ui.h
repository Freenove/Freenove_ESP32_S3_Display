#ifndef __MAIN_UI_H
#define __MAIN_UI_H

#include "public.h"

typedef struct lvgl_main {
  lv_obj_t *main;
  lv_obj_t *main_imgbtn_logo;
  lv_obj_t *main_imgbtn_picture;
  lv_obj_t *main_imgbtn_timer;
  lv_obj_t *main_imgbtn_ws2812;
  lv_obj_t *main_imgbtn_music;
} lvgl_main_ui;  // main ui struct

extern lvgl_main_ui guider_main_ui;     // main ui structure
void setup_scr_main(lvgl_main_ui *ui);  // Parameter configuration function on the main screen

#endif