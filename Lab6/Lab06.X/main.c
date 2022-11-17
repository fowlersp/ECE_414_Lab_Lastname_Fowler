#include "config_clk.h"
#include "ic1.h"
#include "pidControl.h"
#include "oc1_plib.h"
#include "oc2.h"
#include "uart1.h"
#include "ztimer4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userCommands.h"
//lcd includes
//#include "ts_lcd.h" //deprecated in Lab06

#include "adc_intf.h"
#include "tft_master.h"
#include "tft_gfx.h"



#define RX_BUFFER 100

void main(){
    ts_lcd_init();
    setProportionalGain(120);
    setIntegralGain(60);
    setDerivativeGain(30);
    oc1_init_plib(0);
    oc2_init_plib(5000);
    ic1_init();
    uart1_init(115200);
    zTimerSet(100);
    zTimerOn();
    INTEnableSystemMultiVectoredInt();
    char buffer[RX_BUFFER];
    char buffer2[RX_BUFFER];
    char bufferPrev[RX_BUFFER];
    char bufferDesired[RX_BUFFER];
    char bufferCurrent[RX_BUFFER];
    char bufferDesiredPrev[RX_BUFFER];
    char bufferCurrentPrev[RX_BUFFER];
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t x = 0;
    uint8_t lastc = 0;
    uint8_t lastcPrev = 0;
    desiredRPM = 1500;
    while(1){
        if(zTimerReadFlag()){
            int aaa=ic1_getrpm();
            sprintf(bufferDesired, "Desired %d\r\n", desiredRPM);
            sprintf(bufferCurrent, "Desired %d\r\n", aaa);
            //printf("rpm: %d\r ,desiredRPM: %d\r ,actuator: %d\r\n", aaa, desiredRPM, actuator/100);
            printf("error: %d\r ,integ: %d\r ,deriv: %d\r , rpm: %d\r ,desiredRPM: %d\r ,actuator: %d\r\n", error, integ, deriv, aaa, desiredRPM, actuator/100);
            TickPidControl(aaa);//not working, not increasing actuator when increased load/lowered rpm read
//            int go = 3*actuator;
//            if (go>65534){go=65535;}
            oc2_setduty_plib((int)actualRPM*65535);
            oc1_setduty_plib(actuator);
            
            //touchscreen code
            ts_write(bufferDesired, bufferDesiredPrev);
            ts_write(bufferCurrent, bufferCurrentPrev);
            strcpy(bufferDesiredPrev, bufferDesired);
            strcpy(bufferCurrentPrev, bufferCurrent);
            
            
        }
        if(uart1_rxrdy()){
            char tmp = uart1_rxread();
            if(tmp == '\r'){
                //printf("\r\n desiredRPM: %d\r\n", desiredRPM);
                parseUserCommands(buffer2);
                ts_write(buffer2, bufferPrev);
                while(x < lastcPrev){
                    bufferPrev[x] = '\0';
                    x++;
                }
                x = 0;
                while(x < lastc){
                    bufferPrev[x] = buffer2[x];
                    buffer2[x] = '\0';
                    x++;
                }
                x = 0;
                j = 0;
                lastcPrev = lastc;
            }
            buffer[i] = tmp;
            buffer2[j] = tmp;
            j++;
            i++;
            lastc = j;
        }
        if(i > 0 && uart1_txrdy()){
            i--;
            uart1_txwrite(buffer[i]);
        } 
    }
 }
    
    
    
//    zTimerSet(100);
//    zTimerOn();
//    uart1_init(9600);
//    
//    char buffer[RX_BUFFER];
//    uint8_t i = 0;
//    
//    while(1){
//        if(uart1_rxrdy()){
//            char tmp = uart1_rxread();
//            buffer[i] = tmp;
//            i++;
//        }
//        parseUserCommands(buffer);
//        if(i > 0 && uart1_txrdy()){
//            i--;
//            uart1_txwrite(buffer[i]);
//        }
//        if(zTimerReadFlag()){
//            TickPidControl(ic1_getrpm());
//        }
//    }
