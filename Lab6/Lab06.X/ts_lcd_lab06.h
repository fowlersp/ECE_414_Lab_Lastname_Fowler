/* 
 * File:   ts_lcd_lab06.h
 * Author: fowlersp
 *
 * Created on November 17, 2022, 9:36 AM
 */

#ifndef TS_LCD_LAB06_H
#define	TS_LCD_LAB06_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <inttypes.h>
#include "glcdfont.c"
#include "tft_master.h"
#include "tft_gfx.h"

#define x1 160
#define x2 888
#define y1 79
#define y2 907
#define posDesiredRPMX 180
#define posDesiredRPMY 100
#define posActualRPMX 230
#define posActualRPMY 100
#define posCommandX 280
#define posCommandY 100
    
    
    void ts_lcd_lab06_init();
    void ts_desiredRPM_str(char *desiredRPMCurr, char *desiredRPMPrev);
    void ts_actualRPM_str(char *actualRPMCurr, char *actualRPMPrev);
    void ts_command_str(char *commandCurr, char *commandPrev);
    

#ifdef	__cplusplus
}
#endif

#endif	/* TS_LCD_LAB06_H */

