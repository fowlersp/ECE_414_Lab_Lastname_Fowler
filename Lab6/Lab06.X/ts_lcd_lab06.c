
#include "ts_lcd_lab06.h"


void ts_lcd_lab06_init(){
    tft_init_hw();
    tft_begin();
    tft_setRotation(3);
    tft_fillScreen(ILI9341_BLACK);
}

void ts_desiredRPM_str(char *desiredRPMCurr, char *desiredRPMPrev){
    //blacking out previous string by writing over it
    tft_setCursor(posDesiredRPMX, posDesiredRPMY);
    tft_setTextColor(ILI9341_BLACK);
    tft_setTextSize(2);
    tft_writeString(desiredRPMPrev);
    
    //writing new string
    tft_setCursor(posDesiredRPMX, posDesiredRPMY);
    tft_setTextColor(ILI9341_WHITE);
    tft_setTextSize(2);
    tft_writeString(desiredRPMCurr);
}

void ts_actualRPM_str(char *actualRPMCurr, char *actualRPMPrev){
    //blacking out previous string by writing over it
    tft_setCursor(posActualRPMX, posActualRPMY);
    tft_setTextColor(ILI9341_BLACK);
    tft_setTextSize(2);
    tft_writeString(actualRPMPrev);
    
    //writing new string
    tft_setCursor(posActualRPMX, posActualRPMY);
    tft_setTextColor(ILI9341_WHITE);
    tft_setTextSize(2);
    tft_writeString(actualRPMCurr);
}

void ts_command_str(char *commandCurr, char *commandPrev){
    //blacking out previous string by writing over it
    tft_setCursor(posCommandX, posCommandY);
    tft_setTextColor(ILI9341_BLACK);
    tft_setTextSize(2);
    tft_writeString(commandPrev);
    
    //writing new string
    tft_setCursor(posCommandX, posCommandY);
    tft_setTextColor(ILI9341_WHITE);
    tft_setTextSize(2);
    tft_writeString(commandCurr);
}

