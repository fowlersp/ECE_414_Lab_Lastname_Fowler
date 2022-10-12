#include "ts_lcd.h"
#include "glcdfont.c"
#include "stdlib.h"

#define x1 160
#define x2 888
#define y1 79
#define y2 907
#define x1Prime 0
#define x2Prime 319
#define y1Prime 0
#define y2Prime 239
#define zPressedLower 120
#define zPressedUpper 500

void ts_lcd_init(){
    tft_init_hw();
    tft_begin();
    tft_setRotation(3);
    tft_fillScreen(ILI9341_BLACK);
}

uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y){
    struct TSPoint;
    getPoint(&TSPoint);
    int16_t xPoint = TSPoint.x;
    int16_t yPoint = TSPoint.y;
    int16_t zPoint = TSPoint.z;
    *x = (((xPoint- x1)*(x2Prime - x1Prime))/(x2-x1)) + x1Prime;
    *y = (((yPoint- y1)*(y2Prime - y1Prime))/(y2-y1)) + y1Prime;
    if(zPoint >= zPressedLower && zPoint <= zPressedUpper){
        return (uint8_t) 1;
    }else{
        return (uint8_t) 0;
    }
}

void touch_cursor(){
tft.drawFastVLine(ts_lcd_get_ts.x, 0, 240, uint16_t color);
tft.drawFastHLine(0, ts_lcd_get_ts.y, 320, uint16_t color);
//tft.drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
//tft.drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
//tft.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
}