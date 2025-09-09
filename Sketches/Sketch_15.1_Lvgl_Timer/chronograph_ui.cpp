// #include "main_ui.h"
#include "chronograph_ui.h"
#include "lv_img.h"

lvgl_chronograph_ui guider_chronograph_ui;
static uint16_t chronograph_timer_milliseconds = 0;
static uint16_t chronograph_timer_seconds = 0;
static uint16_t chronograph_timer_minutes = 0;
static uint16_t chronograph_timer_hours = 0;
static bool chronograph_timer_state= false;

static uint16_t timer_last_millis=0;
static uint16_t timer_current_millis=0;

static void chronograph_imgbtn_home_event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  switch (code)
  {
  case LV_EVENT_CLICKED:
  {
    Serial.println("Clicked the logo button.");
  }
  break;
  case LV_EVENT_RELEASED:
  {
    /*
    if (!lv_obj_is_valid(guider_main_ui.main))
      setup_scr_main(&guider_main_ui);
    lv_scr_load(guider_main_ui.main);
    lv_obj_del(guider_music_ui.music);
    */
  }
  break;
  default:
    break;
  }
}

static void chronograph_imgbtn_play_event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  switch (code)
  {
    case LV_EVENT_CLICKED:
    {
      Serial.println("Clicked the play button.");
    }
    break;
    case LV_EVENT_RELEASED:
    {
      if(chronograph_timer_state==false)
      {
        Serial.println("Resume the timer.");
        chronograph_timer_state=true;
        lv_timer_resume(guider_chronograph_ui.chronograph_timer);
        timer_last_millis = millis();
        lv_img_set_src(guider_chronograph_ui.chronograph_imgbtn_play, &img_playing);
      }
      else
      {
        Serial.println("Pause the timer.");
        chronograph_timer_state=false;
        lv_timer_pause(guider_chronograph_ui.chronograph_timer);
        lv_img_set_src(guider_chronograph_ui.chronograph_imgbtn_play, &img_pause);
      }
    }
    break;
    default:
      break;
  }
}

static void chronograph_imgbtn_stop_event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  switch (code)
  {
    case LV_EVENT_CLICKED:
    {
      Serial.println("Clicked the stop button.");
    }
    break;
    case LV_EVENT_RELEASED:
    {

        Serial.println("Reset the timer.");
        chronograph_timer_state=false;
        lv_timer_reset(guider_chronograph_ui.chronograph_timer);
        lv_timer_pause(guider_chronograph_ui.chronograph_timer);
        lv_img_set_src(guider_chronograph_ui.chronograph_imgbtn_play, &img_pause);
        chronograph_timer_milliseconds = 0;
        chronograph_timer_seconds = 0;
        chronograph_timer_minutes = 0;
        chronograph_timer_hours = 0;
        lv_label_set_text(guider_chronograph_ui.chronograph_label_show, "0:0:0:00");
    }
    break;
    default:
      break;
  }
}
static void chronograph_timer_event_handler(lv_timer_t *timer)
{
  char buf[256];
  timer_current_millis = millis();
  if(timer_current_millis > timer_last_millis)
  {
    chronograph_timer_milliseconds = chronograph_timer_milliseconds + (timer_current_millis - timer_last_millis);
    timer_last_millis = timer_current_millis;
  }
  if (chronograph_timer_milliseconds >= 1000)
  {
    chronograph_timer_milliseconds = chronograph_timer_milliseconds - 1000;
    chronograph_timer_seconds++;
  }
  if (chronograph_timer_seconds >= 60)
  {
    chronograph_timer_seconds = 0;
    chronograph_timer_minutes++;
  }
  if (chronograph_timer_minutes >= 60)
  {
    chronograph_timer_minutes = 0;
    chronograph_timer_hours++;
  }
  if (chronograph_timer_hours >= 24)
  {
    chronograph_timer_hours = 0;
  }
  lv_snprintf(buf, sizeof(buf), "%d:%d:%d:%2d", chronograph_timer_hours, chronograph_timer_minutes, chronograph_timer_seconds, chronograph_timer_milliseconds/10);
  lv_label_set_text(guider_chronograph_ui.chronograph_label_show, buf);
}

// Parameter configuration function on the chronograph screen
void setup_scr_chronograph(lvgl_chronograph_ui *ui)
{
  // Write codes picture
  ui->chronograph = lv_obj_create(NULL);
  lv_coord_t screen_width = lv_obj_get_width(ui->chronograph);
  lv_coord_t screen_height = lv_obj_get_height(ui->chronograph);

  static lv_style_t bg_style;
  lv_style_init(&bg_style);
  lv_style_set_bg_color(&bg_style, lv_color_hex(0xffffff));
  lv_obj_add_style(ui->chronograph, &bg_style, LV_PART_MAIN);

  lv_img_home_init();
  lv_img_playing_init();
  lv_img_pause_init();
  lv_img_stop_init();

  ui->chronograph_home = lv_imgbtn_create(ui->chronograph);
  lv_obj_remove_style_all(ui->chronograph_home);
  lv_obj_set_size(ui->chronograph_home, 80, 80);
  lv_img_set_src(ui->chronograph_home, &img_home);
  lv_obj_align(ui->chronograph_home, LV_ALIGN_TOP_MID, 0, (screen_height - 180) / 4);
  static lv_style_t style_pr;             // Apply for a style
  lv_style_init(&style_pr);               // Initialize it
  lv_style_set_translate_y(&style_pr, 5); // Style: Every time you trigger, move down 5 pixels
  lv_obj_add_style(ui->chronograph_home, &style_pr, LV_STATE_PRESSED);

  ui->chronograph_btn_show = lv_btn_create(ui->chronograph);
  lv_obj_remove_style_all(ui->chronograph_btn_show);
  lv_obj_set_size(ui->chronograph_btn_show, (screen_width - 40), 40);
  lv_obj_align_to(ui->chronograph_btn_show, ui->chronograph_home, LV_ALIGN_OUT_BOTTOM_MID, 0, (screen_height - 180) / 4);
  ui->chronograph_label_show = lv_label_create(ui->chronograph_btn_show);
  lv_label_set_text(ui->chronograph_label_show, "0:0:0:00");
  lv_obj_center(ui->chronograph_label_show);
  static lv_style_t style_show;
  lv_style_init(&style_show);
  lv_style_set_border_width(&style_show, 2);
  lv_style_set_border_color(&style_show, lv_color_black());
  lv_obj_add_style(ui->chronograph_btn_show, &style_show, LV_PART_MAIN);

  ui->chronograph_imgbtn_play = lv_imgbtn_create(ui->chronograph);
  lv_obj_set_size(ui->chronograph_imgbtn_play, 60, 60);
  lv_img_set_src(ui->chronograph_imgbtn_play, &img_pause);
  lv_obj_align_to(ui->chronograph_imgbtn_play, ui->chronograph_btn_show, LV_ALIGN_OUT_BOTTOM_MID, -(screen_width - 120) / 3, (screen_height - 180) / 4);
  lv_obj_add_style(ui->chronograph_imgbtn_play, &style_pr, LV_STATE_PRESSED);

  ui->chronograph_imgbtn_stop = lv_imgbtn_create(ui->chronograph);
  lv_obj_set_size(ui->chronograph_imgbtn_stop, 60, 60);
  lv_img_set_src(ui->chronograph_imgbtn_stop, &img_stop);
  lv_obj_align_to(ui->chronograph_imgbtn_stop, ui->chronograph_btn_show, LV_ALIGN_OUT_BOTTOM_MID, (screen_width - 120) / 3, (screen_height - 180) / 4);
  lv_obj_add_style(ui->chronograph_imgbtn_stop, &style_pr, LV_STATE_PRESSED);

  lv_obj_add_event_cb(ui->chronograph_home, chronograph_imgbtn_home_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
  lv_obj_add_event_cb(ui->chronograph_imgbtn_play, chronograph_imgbtn_play_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(ui->chronograph_imgbtn_stop, chronograph_imgbtn_stop_event_handler, LV_EVENT_ALL, NULL);

  ui->chronograph_timer = lv_timer_create(chronograph_timer_event_handler, 1, NULL);
  lv_timer_pause(ui->chronograph_timer);
}
