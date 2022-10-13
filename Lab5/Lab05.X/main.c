#include <xc.h>
#include "plib.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include "ts_lcd.h"

/* Clock configuration */
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

uint16_t *xp;
uint16_t *yp;
    
void main(){
    
    char buffer[30];
    
    SYSTEMConfigPerformance(PBCLK);
    
    configureADC();

    ts_lcd_init();
    while(1){
//        if(ts_lcd_get_ts(xp, yp) == 1){
//            //tft_fillScreen(ILI9341_BLACK);
//            tft_setCursor(20, 100);
//            tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);
//
//            //erase old text
//            tft_setTextColor(ILI9341_BLACK);
//            tft_writeString(buffer);
//            tft_setCursor(20, 100);
//            tft_setTextColor(ILI9341_WHITE);
//            sprintf(buffer,"True, x: %d, y: %d", xp, yp);
//            tft_writeString(buffer);
//        }else{
//            //tft_fillScreen(ILI9341_BLACK);
//            tft_setCursor(20, 100);
//            tft_setTextColor(ILI9341_WHITE); tft_setTextSize(2);
//
//            //erase old text
//            tft_setTextColor(ILI9341_BLACK);
//            tft_writeString(buffer);
//            tft_setCursor(20, 100);
//            tft_setTextColor(ILI9341_WHITE);
//            sprintf(buffer,"False");
//            tft_writeString(buffer);
//        }
        
        //ts_lcd_location();
    
        delay_ms(100);
    }
}
