
#include "main_ui.h"

lvgl_main_ui guider_main_ui;  // main ui structure

static void main_imgbtn_logo_event_handler(lv_event_t *event) {
  lv_event_code_t code = lv_event_get_code(event);
  switch (code) {
    case LV_EVENT_CLICKED:
      {
        Serial.println("Clicked the logo button.");
      }
      break;
    case LV_EVENT_RELEASED:
      {
        Serial.println("Released the logo button.");
      }
      break;
    default:
      break;
  }
}

static void main_imgbtn_picture_event_handler(lv_event_t *event) {
  lv_event_code_t code = lv_event_get_code(event);
  switch (code) {
    case LV_EVENT_CLICKED:
      {
        Serial.println("Clicked the picture button.");
      }
      break;
    case LV_EVENT_RELEASED:
      {
        Serial.println("Released the picture button.");
        if (!lv_obj_is_valid(guider_picture_ui.picture))
          setup_scr_picture(&guider_picture_ui);
        lv_scr_load(guider_picture_ui.picture);
        lv_obj_del(guider_main_ui.main);
      }
      break;
    default:
      break;
  }
}

static void main_imgbtn_timer_event_handler(lv_event_t *event) {
  lv_event_code_t code = lv_event_get_code(event);
  switch (code) {
    case LV_EVENT_CLICKED:
      {
        Serial.println("Clicked the timer button.");
      }
      break;
    case LV_EVENT_RELEASED:
      {
        Serial.println("Released the timer button.");
        if (!lv_obj_is_valid(guider_chronograph_ui.chronograph))
          setup_scr_chronograph(&guider_chronograph_ui);
        lv_scr_load(guider_chronograph_ui.chronograph);
        lv_obj_del(guider_main_ui.main);
      }
      break;
    default:
      break;
  }
}

static void main_imgbtn_ws2812_event_handler(lv_event_t *event) {
  lv_event_code_t code = lv_event_get_code(event);
  switch (code) {
    case LV_EVENT_CLICKED:
      {
        Serial.println("Clicked the ws2812 button.");
      }
      break;
    case LV_EVENT_RELEASED:
      {
        Serial.println("Released the ws2812 button.");
        if (!lv_obj_is_valid(guider_ws2812_ui.ws2812))
          setup_scr_ws2812(&guider_ws2812_ui);
        lv_scr_load(guider_ws2812_ui.ws2812);
        lv_obj_del(guider_main_ui.main);
      }
      break;
    default:
      break;
  }
}

static void main_imgbtn_music_event_handler(lv_event_t *event) {
  lv_event_code_t code = lv_event_get_code(event);
  switch (code) {
    case LV_EVENT_CLICKED:
      {
        Serial.println("Clicked the music button.");
      }
      break;
    case LV_EVENT_RELEASED:
      {
        Serial.println("Released the music button.");
        if (!lv_obj_is_valid(guider_music_ui.music))
          setup_scr_music(&guider_music_ui);
        lv_scr_load(guider_music_ui.music);
        lv_obj_del(guider_main_ui.main);
      }
      break;
    default:
      break;
  }
}

// Parameter configuration function on the main screen
void setup_scr_main(lvgl_main_ui *ui) {
  // Write codes main
  ui->main = lv_obj_create(NULL);
  
  static lv_style_t bg_style;
  lv_style_init(&bg_style);
  lv_style_set_bg_color(&bg_style, lv_color_hex(0xffffff));
  lv_obj_add_style(ui->main, &bg_style, LV_PART_MAIN);

  static lv_style_t style_pr;              //Apply for a style
  lv_style_init(&style_pr);                //Initialize it
  lv_style_set_translate_y(&style_pr, 5);  //Style: Every time you trigger, move down 5 pixels
  
  lv_img_freenove_init();
  lv_img_picture_init();
  lv_img_timer_init();
  lv_img_led_init();
  lv_img_music_init();

  //Write codes main_imgbtn_logo
  ui->main_imgbtn_logo = lv_imgbtn_create(ui->main);
  lv_obj_set_pos(ui->main_imgbtn_logo, 40, 20);
  lv_obj_set_size(ui->main_imgbtn_logo, 160, 90);
  lv_img_set_src(ui->main_imgbtn_logo, &img_freenove);
  lv_obj_add_style(ui->main_imgbtn_logo, &style_pr, LV_STATE_PRESSED);  //Triggered when the button is pressed

  //Write codes main_imgbtn_picture
  ui->main_imgbtn_picture = lv_imgbtn_create(ui->main);
  lv_obj_set_pos(ui->main_imgbtn_picture, 20, 135);
  lv_obj_set_size(ui->main_imgbtn_picture, 80, 80);
  lv_img_set_src(ui->main_imgbtn_picture, &img_picture);
  lv_obj_add_style(ui->main_imgbtn_picture, &style_pr, LV_STATE_PRESSED);  //Triggered when the button is pressed

  //Write codes main_imgbtn_timer
  ui->main_imgbtn_timer = lv_imgbtn_create(ui->main);
  lv_obj_set_pos(ui->main_imgbtn_timer, 140, 135);
  lv_obj_set_size(ui->main_imgbtn_timer, 80, 80);
  lv_img_set_src(ui->main_imgbtn_timer, &img_timer);
  lv_obj_add_style(ui->main_imgbtn_timer, &style_pr, LV_STATE_PRESSED);  //Triggered when the button is pressed

  //Write codes main_imgbtn_ws2812
  ui->main_imgbtn_ws2812 = lv_imgbtn_create(ui->main);
  lv_obj_set_pos(ui->main_imgbtn_ws2812, 20, 225);
  lv_obj_set_size(ui->main_imgbtn_ws2812, 80, 80);
  lv_img_set_src(ui->main_imgbtn_ws2812, &img_led);
  lv_obj_add_style(ui->main_imgbtn_ws2812, &style_pr, LV_STATE_PRESSED);  //Triggered when the button is pressed

  //Write codes main_imgbtn_music
  ui->main_imgbtn_music = lv_imgbtn_create(ui->main);
  lv_obj_set_pos(ui->main_imgbtn_music, 140, 225);
  lv_obj_set_size(ui->main_imgbtn_music, 80, 80);
  lv_img_set_src(ui->main_imgbtn_music, &img_music);
  lv_obj_add_style(ui->main_imgbtn_music, &style_pr, LV_STATE_PRESSED);  //Triggered when the button is pressed

  lv_obj_add_event_cb(ui->main_imgbtn_logo, main_imgbtn_logo_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(ui->main_imgbtn_picture, main_imgbtn_picture_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(ui->main_imgbtn_timer, main_imgbtn_timer_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(ui->main_imgbtn_ws2812, main_imgbtn_ws2812_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(ui->main_imgbtn_music, main_imgbtn_music_event_handler, LV_EVENT_ALL, NULL);
}
