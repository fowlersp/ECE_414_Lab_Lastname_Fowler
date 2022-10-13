#include <xc.h>
#include "plib.h"
#include "adc_intf.h"
#include "TouchScreen.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include "ts_lcd.h"
#include "calculator_fsm.h"
#include "uart1.h"
#include <stdio.h>

/* Clock configuration */
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

uint16_t xp;
uint16_t yp;
uint16_t zp;
    
void main(){
    uart1_init(9600);
    printf("testing");
    char buffer[30];
    SYSTEMConfigPerformance(PBCLK);
    zTimerSet(100);
    zTimerOn();
    configureADC();

    ts_lcd_init();
    while(1){
        if(zTimerReadFlag()){
            zp = ts_lcd_get_ts(&xp, &yp);
            if(zp && ((xp >= pos0x) && (xp <= pos0x + width)) && ((yp >= pos0y) && (yp <= pos0y + height))){
                btn = 0x00;
            }else if(zp && ((xp >= pos1x) && (xp <= pos1x + width)) && ((yp >= pos1y) && (yp <= pos1y + height))){
                btn = 0x01;
            }else if(zp && ((xp >= pos2x) && (xp <= pos2x + width)) && ((yp >= pos2y) && (yp <= pos2y + height))){
                btn = 0x02;
            }else if(zp && ((xp >= pos3x) && (xp <= pos3x + width)) && ((yp >= pos3y) && (yp <= pos3y + height))){
                btn = 0x03;
            }else if(zp && ((xp >= pos4x) && (xp <= pos4x + width)) && ((yp >= pos4y) && (yp <= pos4y + height))){
                btn = 0x04;
            }else if(zp && ((xp >= pos5x) && (xp <= pos5x + width)) && ((yp >= pos5y) && (yp <= pos5y + height))){
                btn = 0x05;
            }else if(zp && ((xp >= pos6x) && (xp <= pos6x + width)) && ((yp >= pos6y) && (yp <= pos6y + height))){
                btn = 0x06;
            }else if(zp && ((xp >= pos7x) && (xp <= pos7x + width)) && ((yp >= pos7y) && (yp <= pos7y + height))){
                btn = 0x07;
            }else if(zp && ((xp >= pos8x) && (xp <= pos8x + width)) && ((yp >= pos8y) && (yp <= pos8y + height))){
                btn = 0x08;
            }else if(zp && ((xp >= pos9x) && (xp <= pos9x + width)) && ((yp >= pos9y) && (yp <= pos9y + height))){
                btn = 0x09;
            }else if(zp && ((xp >= posplusx) && (xp <= posplusx + width)) && ((yp >= posplusy) && (yp <= posplusy + height))){
                btn = plus;
            }else if(zp && ((xp >= possubx) && (xp <= possubx + width)) && ((yp >= possuby) && (yp <= possuby + height))){
                btn = sub;
            }else if(zp && ((xp >= posmulx) && (xp <= posmulx + width)) && ((yp >= posmuly) && (yp <= posmuly + height))){
                btn = mult;
            }else if(zp && ((xp >= posdivx) && (xp <= posdivx + width)) && ((yp >= posdivy) && (yp <= posdivy + height))){
                btn = div;
            }else if(zp && ((xp >= posequx) && (xp <= posequx + width)) && ((yp >= posequy) && (yp <= posequy + height))){
                btn = equ;
            }else if(zp && ((xp >= posCx) && (xp <= posCx + width)) && ((yp >= posCy) && (yp <= posCy + height))){
                btn = C;
                result = 0;
            }
            if(zp){
                Tick_CSStates();
                if(calculation_error == DIVBy0){
                    ts_writeString("DivBy0");
                }else if(calculation_error == OVERFLOW){
                    ts_writeString("Overflow");
                }else{
                    if(result == 0 && btn > equ){
                        ts_writeString(buffer);
                    }else if(btn < C){
                        sprintf(buffer, "%s%c", buffer, btn + 0x48);
                        ts_writeString(buffer);
                    }else if(btn >= equ){
                        sprintf(buffer, "%d", result);
                        ts_writeString(buffer);
                    }else if(btn == C){
                        sprintf(buffer, "%s", "0");
                        ts_writeString(buffer);
                    }
                }
            }
        }
        //delay_ms(100);
    }
}
