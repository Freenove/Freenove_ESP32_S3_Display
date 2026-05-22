#include "display.h"

#ifdef FNK0104N_3P5_320x480_ST77922
  static const uint16_t screenWidth  = 320;
  static const uint16_t screenHeight = 480;
#elif defined FNK0104AB_2P8_240x320_ILI9341
  static const uint16_t screenWidth  = 240;
  static const uint16_t screenHeight = 320;
#elif defined FNK0104S_4P0_320x480_ST7796
  static const uint16_t screenWidth  = 320;
  static const uint16_t screenHeight = 480;
#endif

#ifdef FNK0104N_3P5_320x480_ST77922
 #include <SPI.h>
 #include "ST77922.h"

 static lv_disp_draw_buf_t draw_buf;
 static lv_color_t buf[ 480 * 40 ];

 ST77922 tft_st77922 = ST77922();

 void my_rounder_cb(lv_disp_drv_t * disp_drv, lv_area_t * area)
 {
   area->x1 = area->x1 & ~0x3;
   area->y1 = area->y1 & ~0x3;

   area->x2 = area->x2 | 0x3;
   area->y2 = area->y2 | 0x3;
 }

#else
 static lv_disp_draw_buf_t draw_buf;
 static lv_color_t buf[ screenWidth * 40 ];

 TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */
#endif

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );
    
    #if defined FNK0104N_3P5_320x480_ST77922
      tft_st77922.Fill_Colors(area->x1, area->y1, w, h, (uint16_t *)color_p);
    #else
      tft.startWrite();
      tft.setAddrWindow( area->x1, area->y1, w, h );
      tft.pushColors((uint16_t*)&color_p->full, w * h, true );
      tft.endWrite();
    #endif

    lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{

}

void Display::init(void)
{
#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif
    #ifdef FNK0104N_3P5_320x480_ST77922
      tft_st77922.Init();
      tft_st77922.Set_Rotation(TFT_DIRECTION);
      
      lv_init();
      lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 40 );
    #else
      lv_init();
      tft.begin();          /* TFT init */
      tft.setRotation( TFT_DIRECTION ); /* Landscape orientation, flipped */
      lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );
    #endif
    
    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    #ifdef FNK0104N_3P5_320x480_ST77922
      disp_drv.rounder_cb = my_rounder_cb;
    #endif
    
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register( &indev_drv );
}

void Display::routine(void)
{
    lv_task_handler();
}
