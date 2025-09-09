#ifndef __CHRONOGRAPH_UI_H
#define __CHRONOGRAPH_UI_H

#include "public.h"

typedef struct lvgl_chronograph
{
	lv_obj_t *chronograph;
  lv_obj_t *chronograph_home;

  lv_obj_t *chronograph_imgbtn_play;
  lv_obj_t *chronograph_imgbtn_stop;
  lv_obj_t *chronograph_btn_show;

  lv_obj_t *chronograph_label_show;
  lv_timer_t *chronograph_timer;
}lvgl_chronograph_ui;

extern lvgl_chronograph_ui guider_chronograph_ui;    //chronograph ui structure 

void setup_scr_chronograph(lvgl_chronograph_ui *ui); //Parameter configuration function on the chronograph screen

#endif
