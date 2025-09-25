#ifndef __LV_IMG_H
#define __LV_IMG_H

#define SELECT_IMG_SIZE_60   (60)
#define SELECT_IMG_SIZE_80   (80)
#define SELECT_IMG_SIZE_100  (100)

#define SELECT_IMG_HOME      SELECT_IMG_SIZE_80
#define SELECT_IMG_LED       SELECT_IMG_SIZE_80
#define SELECT_IMG_MUSIC     SELECT_IMG_SIZE_80
#define SELECT_IMG_PICTURE   SELECT_IMG_SIZE_80
#define SELECT_IMG_TIMER     SELECT_IMG_SIZE_80
#define SELECT_IMG_CAMERA    SELECT_IMG_SIZE_80
#define SELECT_IMG_HEARTBEAT SELECT_IMG_SIZE_80
#define SELECT_IMG_RECORDER  SELECT_IMG_SIZE_80
#define SELECT_IMG_LEFT      SELECT_IMG_SIZE_60
#define SELECT_IMG_RIGHT     SELECT_IMG_SIZE_60
#define SELECT_IMG_PLAYING   SELECT_IMG_SIZE_60
#define SELECT_IMG_PAUSE     SELECT_IMG_SIZE_60
#define SELECT_IMG_STOP      SELECT_IMG_SIZE_60

extern lv_img_dsc_t img_freenove;
extern lv_img_dsc_t img_home;
extern lv_img_dsc_t img_led;
extern lv_img_dsc_t img_music;
extern lv_img_dsc_t img_picture;
extern lv_img_dsc_t img_timer;
extern lv_img_dsc_t img_camera;
extern lv_img_dsc_t img_heartbeat;
extern lv_img_dsc_t img_recorder;
extern lv_img_dsc_t img_left;
extern lv_img_dsc_t img_right;
extern lv_img_dsc_t img_playing;
extern lv_img_dsc_t img_pause;
extern lv_img_dsc_t img_stop;

void lv_img_freenove_init(void);
void lv_img_home_init(void);
void lv_img_led_init(void);
void lv_img_music_init(void);
void lv_img_picture_init(void);
void lv_img_timer_init(void);
void lv_img_camera_init(void);
void lv_img_heartbeat_init(void);
void lv_img_recorder_init(void);
void lv_img_left_init(void);
void lv_img_right_init(void);
void lv_img_playing_init(void);
void lv_img_pause_init(void);
void lv_img_stop_init(void);


#endif



