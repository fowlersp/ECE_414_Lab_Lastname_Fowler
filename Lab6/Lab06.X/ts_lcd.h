/* 
 * File:   ts_lcd.h
 * Author: sonkinj
 *
 * Created on October 6, 2022, 9:04 AM
 */

#ifndef TS_LCD_H
#define	TS_LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* TS_LCD_H */
#include <inttypes.h>

#define x1 160
#define x2 888
#define y1 79
#define y2 907
#define x1Prime 0
#define x2Prime 319
#define y1Prime 0
#define y2Prime 239
#define zPressedLower 70
#define zPressedUpper 800
#define pos0x 10
#define pos0y 190
#define pos1x 10
#define pos1y 140
#define pos2x 80
#define pos2y 140
#define pos3x 150
#define pos3y 140
#define pos4x 10
#define pos4y 90
#define pos5x 80
#define pos5y 90
#define pos6x 150
#define pos6y 90
#define pos7x 10
#define pos7y 40
#define pos8x 80
#define pos8y 40
#define pos9x 150
#define pos9y 40
#define posplusx 220
#define posplusy 40
#define possubx 220
#define possuby 90
#define posmulx 220
#define posmuly 140
#define posdivx 220
#define posdivy 190
#define posequx 150
#define posequy 190
#define posCx 80
#define posCy 190
#define width 65
#define height 45

#define ppos0x 260
#define ppos0y 190
#define ppos1x 190
#define ppos1y 190
#define ppos2x 190
#define ppos2y 140
#define ppos3x 190
#define ppos3y 90
#define ppos4x 120
#define ppos4y 190
#define ppos5x 120
#define ppos5y 140
#define ppos6x 120
#define ppos6y 90
#define ppos7x 50
#define ppos7y 190
#define ppos8x 50
#define ppos8y 140
#define ppos9x 50
#define ppos9y 90
#define pposplusx 50
#define pposplusy 40
#define ppossubx 120
#define ppossuby 40
#define pposmulx 190
#define pposmuly 40
#define pposdivx 260
#define pposdivy 40
#define pposequx 260
#define pposequy 90
#define pposCx 260
#define pposCy 140

void ts_lcd_init();
uint8_t ts_lcd_get_ts(uint16_t *x, uint16_t *y);
void ts_writeString(char* str);
void ts_write(char str1[30], char str2[30]);



