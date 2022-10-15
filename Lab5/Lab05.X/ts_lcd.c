#include "ts_lcd.h"
#include "glcdfont.c"
#include "tft_master.h"
#include "tft_gfx.h"
#include "stdlib.h"
#include "TouchScreen.h"

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

int value = 0; 

void ts_lcd_init(){
    tft_init_hw();
    tft_begin();
    tft_setRotation(3);
    tft_fillScreen(ILI9341_BLACK);
    
    //Draw calculator
    tft_fillRoundRect(10, 40, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(10, 90, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(10, 140, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(10, 190, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(80, 40, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(80, 90, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(80, 140, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(80, 190, 65, 45, 5, ILI9341_RED);
    tft_fillRoundRect(150, 40, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(150, 90, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(150, 140, 65, 45, 5, ILI9341_WHITE);
    tft_fillRoundRect(150, 190, 65, 45, 5, ILI9341_BLUE);
    tft_fillRoundRect(220, 40, 65, 45, 5, ILI9341_GREEN);
    tft_fillRoundRect(220, 90, 65, 45, 5, ILI9341_GREEN);
    tft_fillRoundRect(220, 140, 65, 45, 5, ILI9341_GREEN);
    tft_fillRoundRect(220, 190, 65, 45, 5, ILI9341_GREEN);
    
    tft_setCursor(15, 5);
    tft_setTextColor(ILI9341_WHITE); 
    tft_setTextSize(2);
    tft_writeString("Number");
    
    tft_setTextColor(ILI9341_BLACK); 
    tft_setTextSize(2);
    tft_setCursor(38, 56);
    tft_writeString("7");
    tft_setCursor(38, 106);
    tft_writeString("4");
    tft_setCursor(38, 156);
    tft_writeString("1");
    tft_setCursor(38, 206);
    tft_writeString("0");
    tft_setCursor(108, 56);
    tft_writeString("8");
    tft_setCursor(108, 106);
    tft_writeString("5");
    tft_setCursor(108, 156);
    tft_writeString("2");
    tft_setCursor(108, 206);
    tft_writeString("C");
    tft_setCursor(178, 56);
    tft_writeString("9");
    tft_setCursor(178, 106);
    tft_writeString("6");
    tft_setCursor(178, 156);
    tft_writeString("3");
    tft_setCursor(178, 206);
    tft_writeString("=");
    tft_setCursor(248, 56);
    tft_writeString("+");
    tft_setCursor(248, 106);
    tft_writeString("-");
    tft_setCursor(248, 156);
    tft_writeString("x");
    tft_setCursor(248, 206);
    tft_writeString("/");
    
}

uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y){
    struct TSPoint p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    getPoint(&p);
    int16_t xPoint = p.x;
    int16_t yPoint = p.y;
    int16_t zPoint = p.z;
    *x = (((xPoint- x1)*(x2Prime - x1Prime))/(x2-x1)) + x1Prime;
    *y = (((yPoint- y1)*(y2Prime - y1Prime))/(y2-y1)) + y1Prime;
    if(zPoint >=zPressedLower && zPoint <= zPressedUpper){
        return (uint8_t) 1;
    }else{
        return (uint8_t) 0;
    }
}

void ts_lcd_location(){
    char buffer[30];
    
    //tft_fillScreen(ILI9341_BLACK);
    tft_setCursor(20, 100);
    tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);

    //erase old text
    tft_setTextColor(ILI9341_BLACK);
    tft_writeString(buffer);
        
    struct TSPoint p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    getPoint(&p);
    tft_setCursor(20, 100);
    tft_setTextColor(ILI9341_WHITE);
    short xs = (p.x + 20)-200;//- x1)*(x2Prime - x1Prime))/(x2-x1)) + x1Prime;
    short xe = (p.x - 20)-200;//- x1)*(x2Prime - x1Prime))/(x2-x1)) + x1Prime;
    short ys = (p.y + 20);//- y1)*(y2Prime - y1Prime))/(y2-y1)) + y1Prime;
    short ye = (p.y - 20);//- y1)*(y2Prime - y1Prime))/(y2-y1)) + y1Prime;
    tft_drawLine(ys, xs, ye, xe, ILI9341_WHITE);
    sprintf(buffer,"x: %d, y: %d, z: %d", p.x, p.y, p.z);
    tft_writeString(buffer);
    
}


    
//void touch_cursor(){
//tft.drawFastVLine(ts_lcd_get_ts.x, 0, 240, uint16_t color);
//tft.drawFastHLine(0, ts_lcd_get_ts.y, 320, uint16_t color);
//tft.drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
//tft.drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
//tft.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
