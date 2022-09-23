/* Clock configuration */
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <xc.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>
#include "porta_in.h"
#include "portb_out.h"
#include "ztimer.h"

//#define PERIOD_DB 50
//#define PERIOD_G 200

const uint16_t LED_CONST = 0x0001;
volatile unsigned char TimerFlag = 0;
unsigned char l_btndown;
unsigned char r_btndown;
uint16_t spdMult25ms = 12;

void TimerISR(){
    TimerFlag = 1;
}

enum PONG_States {PONG_START, PONG_SERVE, PONG_MOVELEDL, PONG_MOVELEDR, PONG_LOSEL, PONG_LOSER, PONG_Default} PONG_States;

void Tick_PONGStates(){
    static int cnt = 1;
    static int flash = 0;
    static unsigned char lr = 0;
    //srand(time(NULL));
    switch(PONG_States){
        case PONG_START:
            lr = rand() % 2;
            spdMult25ms = 12;
            PONG_States = PONG_SERVE; //maybe move this to after the if else statements
            if(lr == 1){
                portb_out_write(LED_CONST << 7);
            }else{
                portb_out_write(LED_CONST);
            }
            break;
        case PONG_SERVE:
            if((l_btndown && r_btndown)){ //should be replaced with if(!(l_btndown || r_btndown)) sw2 = r_btndown
                PONG_States = PONG_SERVE;
            }else if((lr == 1) && !l_btndown && r_btndown){
                cnt = 7;
                portb_out_write(0x0100);
                PONG_States = PONG_MOVELEDR;
            }else if((lr == 0) && l_btndown && !r_btndown){
                cnt = 0;
                portb_out_write(0x0400);
                PONG_States = PONG_MOVELEDL;
            }
//            else{
//                PONG_States = PONG_Default;
//            }
            break;
        case PONG_MOVELEDL:
            if((cnt>=1 && cnt < 6) && !l_btndown){
                PONG_States = PONG_LOSEL;
                flash = 0;
            }else if((cnt == 7) && !l_btndown){
                PONG_States = PONG_MOVELEDR;
                spdMult25ms = spdMult25ms-2;
            }else if((cnt > 7)){
                PONG_States = PONG_LOSEL;
                flash = 0;
            }else if(cnt < 8){
               PONG_States = PONG_MOVELEDL;
            }else{
               PONG_States = PONG_Default;
            }
            portb_out_write(LED_CONST << cnt);
            cnt++;
            break;
        case PONG_MOVELEDR:
            if((cnt >= 1 && cnt < 7) && !r_btndown){
                PONG_States = PONG_LOSER;
                flash = 0;
            }else if((cnt == 0) && !r_btndown){
                PONG_States = PONG_MOVELEDL;
                spdMult25ms = spdMult25ms-2;
            }else if((cnt < 1)){
                PONG_States = PONG_LOSER;
                flash = 0;
            }else if(cnt > 0){
               PONG_States = PONG_MOVELEDR;
            }else{
                PONG_States = PONG_Default;
            }
            portb_out_write(LED_CONST << cnt);
            cnt--;
            break;
        case PONG_LOSEL:
            if(flash != 5){
                if(flash % 2){
                    portb_out_write(LED_CONST << 7);
                }else{
                    portb_out_write(0);
                }
                flash++;
                PONG_States = PONG_LOSEL;
            }else{
                PONG_States = PONG_START;
            }
            break;
        case PONG_LOSER:
            if(flash != 5){
                if(flash % 2){
                    portb_out_write(LED_CONST);
                }else{
                    portb_out_write(0);
                }
                flash++;
                PONG_States = PONG_LOSER;
            }else{
                PONG_States = PONG_START;
            }
            break;
        case PONG_Default:
            portb_out_write(0x00FF);    
        default:
            break;
    }
}

enum DEBOUNCEL {DEBOUNCEL_NOPUSH, DEBOUNCEL_MAYBEPUSH, DEBOUNCEL_MAYBENOPUSH, DEBOUNCEL_PUSHED} DEBOUNCEL;

void Tick_DEBOUNCEL(unsigned char l_btn){
    switch(DEBOUNCEL){
        case DEBOUNCEL_NOPUSH:
            if(!l_btn){
                DEBOUNCEL = DEBOUNCEL_NOPUSH;
            }else{
                DEBOUNCEL = DEBOUNCEL_MAYBEPUSH;
            }
            break;
        case DEBOUNCEL_MAYBEPUSH:
            if(!l_btn){
                DEBOUNCEL = DEBOUNCEL_NOPUSH;
            }else{
                DEBOUNCEL = DEBOUNCEL_PUSHED;
                l_btndown = 1;
            }
            break;
        case DEBOUNCEL_PUSHED:
            if(!l_btn){
                DEBOUNCEL = DEBOUNCEL_MAYBENOPUSH;
            }else{
                DEBOUNCEL = DEBOUNCEL_PUSHED;
            }
            break;
        case DEBOUNCEL_MAYBENOPUSH:
            if(!l_btn){
                DEBOUNCEL = DEBOUNCEL_NOPUSH;
                l_btndown = 0;
            }else{
                DEBOUNCEL = DEBOUNCEL_PUSHED;
            }
            break;
        default:
            break;
    }
}

enum DEBOUNCER {DEBOUNCER_NOPUSH, DEBOUNCER_MAYBEPUSH, DEBOUNCER_MAYBENOPUSH, DEBOUNCER_PUSHED} DEBOUNCER;

void Tick_DEBOUNCER(unsigned char r_btn){
    switch(DEBOUNCER){
        case DEBOUNCER_NOPUSH:
            if(!r_btn){
                DEBOUNCER = DEBOUNCER_NOPUSH;
            }else{
                DEBOUNCER = DEBOUNCER_MAYBEPUSH;
            }
            break;
        case DEBOUNCER_MAYBEPUSH:
            if(!r_btn){
                DEBOUNCER = DEBOUNCER_NOPUSH;
            }else{
                DEBOUNCER = DEBOUNCER_PUSHED;
                r_btndown = 1;
            }
            break;
        case DEBOUNCER_PUSHED:
            if(!r_btn){
                DEBOUNCER = DEBOUNCER_MAYBENOPUSH;
            }else{
                DEBOUNCER = DEBOUNCER_PUSHED;
            }
            break;
        case DEBOUNCER_MAYBENOPUSH:
            if(!r_btn){
                DEBOUNCER = DEBOUNCER_NOPUSH;
                r_btndown = 0;
            }else{
                DEBOUNCER = DEBOUNCER_PUSHED;
            }
            break;
        default:
            break;
    }
}

void main(){
    porta_in_init();
    portb_out_init();
    char sw1, sw2, in;
    uint8_t loop = 0;
    zTimerSet(25);
    zTimerOn();
    while(1){
        in = porta_in_read();
        sw1 = in & 0x01;
        sw2 = in & 0x02;
        sw2 =  sw2 >> 1;
        if(zTimerReadFlag()){
            Tick_DEBOUNCEL(sw1);
            Tick_DEBOUNCER(sw2);
            loop++;
            if(loop == spdMult25ms){
                Tick_PONGStates();
                loop = 0;
            }
            if(spdMult25ms<5){spdMult25ms=4;}
        }
    }
//    uint32_t period_game, t1db, t2db, t1g, t2g;
//    t1db = t1g = zTimerReadms();
//    
//    while(1){
//    //call states
//        t2db = t2g = zTimerReadms();
//        in = porta_in_read();
//        sw1 = in & 0x01;
//        sw2 = (in & 0x02)>>1;
//        if((t2db-t1db)>=50){
//            t2db=t1db;
//            Tick_DEBOUNCEL(sw1);
//            Tick_DEBOUNCER(sw2);
//        }
//        if((t2g-t1g)>=200){
//            t2g = t1g;
//            Tick_PONGStates();
//        } 
//    }
   
}