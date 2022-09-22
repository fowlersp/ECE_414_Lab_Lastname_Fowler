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

const uint16_t LED_CONST = 0x0001;
volatile unsigned char TimerFlag = 0;
unsigned char l_btndown;
unsigned char r_btndown;

void TimerISR(){
    TimerFlag = 1;
}

enum PONG_States {PONG_START, PONG_SERVE, PONG_MOVELEDL, PONG_MOVELEDR, PONG_LOSEL, PONG_LOSER} PONG_States;

void Tick_PONGStates(unsigned char sw1, unsigned char sw2){
    static int cnt = 1;
    static unsigned char lr = 0;
    srand(time(NULL));
    switch(PONG_States){
        case PONG_START:
            lr = rand() % 2;
            PONG_States = PONG_SERVE; //maybe move this to after the if else statements
            if(lr){
                portb_out_write(LED_CONST << 7);
            }else{
                portb_out_write(LED_CONST);
            }
            break;
        case PONG_SERVE:
            if(!(sw1 || sw2)){
                PONG_States = PONG_SERVE;
            }else if((lr == 0) && sw1 && !sw2){
                cnt = 1;
                PONG_States = PONG_MOVELEDL;
            }else if((lr == 1) && !sw1 && sw2){
                cnt = 8;
                PONG_States = PONG_MOVELEDR;
            }
            break;
        case PONG_MOVELEDL:
            if(cnt< 8){
               PONG_States = PONG_MOVELEDL; 
            }
            else if((cnt>=1 && cnt < 8) && sw2){
                PONG_States = PONG_LOSEL;
                cnt = 0;
            }else if((cnt == 8) && sw2){
                PONG_States = PONG_MOVELEDR;
            }else if((cnt == 8) && !sw2){
                PONG_States == PONG_LOSEL;
                cnt = 0;
            }
            portb_out_write(LED_CONST << cnt);
            cnt++;
            break;
        case PONG_MOVELEDR:
            if(cnt > 1){
               PONG_States = PONG_MOVELEDR; 
            }
            else if((cnt>=1 && cnt < 8) && sw1){
                PONG_States = PONG_LOSER;
                cnt = 0;
            }else if((cnt == 8) && sw1){
                PONG_States = PONG_MOVELEDL;
            }else if((cnt == 8) && !sw1){
                PONG_States == PONG_LOSER;
                cnt = 0;
            }
            portb_out_write(LED_CONST >> cnt); //Note this should be portb_out_write(LED_CONST << cnt) still
            cnt--;
            break;
        case PONG_LOSEL:
            if(cnt != 5){
                if(cnt % 2){
                    portb_out_write(LED_CONST << 7);
                }else{
                    portb_out_write(0);
                }
                cnt++;
                PONG_States = PONG_LOSEL;
            }else{
                PONG_States = PONG_SERVE;
            }
            break;
        case PONG_LOSER:
            if(cnt != 5){
                if(cnt % 2){
                    portb_out_write(LED_CONST);
                }else{
                    portb_out_write(0);
                }
                cnt++;
                PONG_States = PONG_LOSER;
            }else{
                PONG_States = PONG_SERVE;
            }
            break;
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
    zTimerSet(200);
    zTimerOn();
    
    while(1){
    //call states
        in = porta_in_read();
        sw1 = in & 0x01;
        sw2 = in & 0x02;
        if(zTimerReadFlag()){
            Tick_DEBOUNCEL(sw1);
            Tick_DEBOUNCER(sw2);
            Tick_PONGStates(sw1, sw2);
        }
        
    }
    
}


