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
uint16_t zp1;

//enum DEBOUNCEL {DEBOUNCEL_NOPUSH, DEBOUNCEL_MAYBEPUSH, DEBOUNCEL_MAYBENOPUSH, DEBOUNCEL_PUSHED} DEBOUNCEL;
//
//void Tick_DEBOUNCE(unsigned char l_btn){
//    switch(DEBOUNCEL){
//        case DEBOUNCEL_NOPUSH:
//            if(!l_btn){
//                DEBOUNCEL = DEBOUNCEL_NOPUSH;
//            }else{
//                DEBOUNCEL = DEBOUNCEL_MAYBEPUSH;
//            }
//            break;
//        case DEBOUNCEL_MAYBEPUSH:
//            if(!l_btn){
//                DEBOUNCEL = DEBOUNCEL_NOPUSH;
//            }else{
//                DEBOUNCEL = DEBOUNCEL_PUSHED;
//                zp = 1;
//            }
//            break;
//        case DEBOUNCEL_PUSHED:
//            if(!l_btn){
//                DEBOUNCEL = DEBOUNCEL_MAYBENOPUSH;
//            }else{
//                DEBOUNCEL = DEBOUNCEL_PUSHED;
//            }
//            break;
//        case DEBOUNCEL_MAYBENOPUSH:
//            if(!l_btn){
//                DEBOUNCEL = DEBOUNCEL_NOPUSH;
//            }else{
//                DEBOUNCEL = DEBOUNCEL_PUSHED;
//            }
//            break;
//        default:
//            break;
//    }
//}
    
void main(){
    uart1_init(9600);
    printf("testing");
    char buffer[30];
    SYSTEMConfigPerformance(PBCLK);
    zTimerSet(50);
    zTimerOn();
    configureADC();

    ts_lcd_init();
    while(1){
        if(zTimerReadFlag()){
            zp = ts_lcd_get_ts(&xp, &yp);
            //Tick_DEBOUNCE(zp1);
            if(zp && ((xp >= ppos0x) && (xp <= ppos0x + width)) && ((yp >= ppos0y) && (yp <= ppos0y + height))){
                btn = 0x00;
            }else if(zp && ((xp >= ppos1x) && (xp <= ppos1x + width)) && ((yp >= ppos1y) && (yp <= ppos1y + height))){
                btn = 0x01;
            }else if(zp && ((xp >= ppos2x) && (xp <= ppos2x + width)) && ((yp >= ppos2y) && (yp <= ppos2y + height))){
                btn = 0x02;
            }else if(zp && ((xp >= ppos3x) && (xp <= ppos3x + width)) && ((yp >= ppos3y) && (yp <= ppos3y + height))){
                btn = 0x03;
            }else if(zp && ((xp >= ppos4x) && (xp <= ppos4x + width)) && ((yp >= ppos4y) && (yp <= ppos4y + height))){
                btn = 0x04;
            }else if(zp && ((xp >= ppos5x) && (xp <= ppos5x + width)) && ((yp >= ppos5y) && (yp <= ppos5y + height))){
                btn = 0x05;
            }else if(zp && ((xp >= ppos6x) && (xp <= ppos6x + width)) && ((yp >= ppos6y) && (yp <= ppos6y + height))){
                btn = 0x06;
            }else if(zp && ((xp >= ppos7x) && (xp <= ppos7x + width)) && ((yp >= ppos7y) && (yp <= ppos7y + height))){
                btn = 0x07;
            }else if(zp && ((xp >= ppos8x) && (xp <= ppos8x + width)) && ((yp >= ppos8y) && (yp <= ppos8y + height))){
                btn = 0x08;
            }else if(zp && ((xp >= ppos9x) && (xp <= ppos9x + width)) && ((yp >= ppos9y) && (yp <= ppos9y + height))){
                btn = 0x09;
            }else if(zp && ((xp >= pposplusx) && (xp <= pposplusx + width)) && ((yp >= pposplusy) && (yp <= pposplusy + height))){
                btn = plus;
            }else if(zp && ((xp >= ppossubx) && (xp <= ppossubx + width)) && ((yp >= ppossuby) && (yp <= ppossuby + height))){
                btn = sub;
            }else if(zp && ((xp >= pposmulx) && (xp <= pposmulx + width)) && ((yp >= pposmuly) && (yp <= pposmuly + height))){
                btn = mult;
            }else if(zp && ((xp >= pposdivx) && (xp <= pposdivx + width)) && ((yp >= pposdivy) && (yp <= pposdivy + height))){
                btn = div;
            }else if(zp && ((xp >= pposequx) && (xp <= pposequx + width)) && ((yp >= pposequy) && (yp <= pposequy + height))){
                btn = equ;
            }else if(zp && ((xp >= pposCx) && (xp <= pposCx + width)) && ((yp >= pposCy) && (yp <= pposCy + height))){
                btn = C;
                result = 0;
            }
            
            if(zp){
                Tick_CSStates();
//                if(calculation_error == DIVBy0){
//                    ts_writeString("DivBy0");
//                }else if(calculation_error == OVERFLOW){
//                    ts_writeString("Overflow");
//                }else{
//                    if(result == 0 && btn > equ){
//                        ts_writeString(buffer);
//                    }else if(btn < C){
//                        sprintf(buffer, "%s%c", buffer, btn + 0x48);
//                        ts_writeString(buffer);
//                    }else if(btn >= equ){
//                        sprintf(buffer, "%d", result);
//                        ts_writeString(buffer);
//                    }else if(btn == C){
//                        sprintf(buffer, "%s", "0");
//                        ts_writeString(buffer);
//                    }
//                }
            }
        }
        //delay_ms(100);
    }
}
