
#include "glcdfont.c"
#include "tft_master.h"
#include "tft_gfx.h"
#include "stdlib.h"
#include "TouchScreen.h"
#include "ts_lcd.h"

int value = 0; 
char val = 0;

void ts_lcd_init(){
    tft_init_hw();
    tft_begin();
    tft_setRotation(3);
    tft_fillScreen(ILI9341_BLACK);
}

void ts_writeString(char* str){
    tft_setCursor(15, 5);
    tft_setTextColor(ILI9341_WHITE); 
    tft_setTextSize(2);
    tft_writeString(str);
}

void ts_write(char str1[30], char str2[30]){
    tft_setCursor(15, 5);
    tft_setTextColor(ILI9341_BLACK); 
    tft_setTextSize(2);
    tft_writeString(str2);
    tft_setCursor(15, 5);
    tft_setTextColor(ILI9341_WHITE); 
    tft_setTextSize(2);
    tft_writeString(str1);
}
/*

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
*/

    
//void touch_cursor(){
//tft.drawFastVLine(ts_lcd_get_ts.x, 0, 240, uint16_t color);
//tft.drawFastHLine(0, ts_lcd_get_ts.y, 320, uint16_t color);
//tft.drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
//tft.drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
//tft.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)

/*
void numb_press(int x, int y){
    if((x >= 10 && x <= 75) && (y >= 40 && y <= 85)){
        value = value*10 + 7;
    }
    else if((x >= 10 && x <= 75) && (y >= 90 && y <= 135)){
        value = value*10 + 4;
    }
    else if((x >= 10 && x <= 75) && (y >= 140 && y <= 185)){
        value = value*10 + 1;
    }
    else if((x >= 10 && x <= 75) && (y >= 190 && y <= 235)){
        value = value*10 + 0;
    }
    else if((x >= 80 && x <= 1height) && (y >= 40 && y <= 85)){
        value = value*10 + 8;
    }
    else if((x >= 80 && x <= 1height) && (y >= 90 && y <= 135)){
        value = value*10 + 5;
    }
    else if((x >= 80 && x <= 1height) && (y >= 140 && y <= 185)){
        value = value*10 + 2;
    }
    else if((x >= 80 && x <= 1height) && (y >= 190 && y <= 235)){
        // clear function
    }
    else if((x >= 150 && x <= 215) && (y >= 40 && y <= 85)){
        value = value*10 + 9;
    }
    else if((x >= 150 && x <= 215) && (y >= 90 && y <= 135)){
        value = value*10 + 6;
    }
    else if((x >= 150 && x <= 215) && (y >= 140 && y <= 185)){
        value = value*10 + 3;
    }
    else if((x >= 150 && x <= 215) && (y >= 190 && y <= 235)){
        // equal function
    }
    else if((x >= 220 && x <= 275) && (y >= 40 && y <= 85)){
        //add
    }
    else if((x >= 220 && x <= 275) && (y >= 90 && y <= 135)){
        //subtract
    }
    else if((x >= 220 && x <= 275) && (y >= 140 && y <= 185)){
        //multiply
    }
    else if((x >= 220 && x <= 275) && (y >= 190 && y <= 235)){
        //divide
    }
    */

/*
void touch_cursor(){
tft.drawFastVLine(ts_lcd_get_ts.x, 0, 240, uint16_t color);
tft.drawFastHLine(0, ts_lcd_get_ts.y, 320, uint16_t color);
//tft.drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
//tft.drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
//tft.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
}
 */
