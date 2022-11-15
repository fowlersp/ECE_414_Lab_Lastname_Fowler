#include "config_clk.h"
#include "ic1.h"
#include "pidControl.h"
#include "oc1_plib.h"
//#include "oc2.h"
#include "uart1.h"
#include "ztimer4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userCommands.h"

#define RX_BUFFER 100

void main(){
    setProportionalGain(400);
    setIntegralGain(3);
    setDerivativeGain(10);
    oc1_init_plib(0);
    //oc2_init_plib(0);
    ic1_init();
    uart1_init(9600);
    zTimerSet(35);
    zTimerOn();
    INTEnableSystemMultiVectoredInt();
    char buffer[RX_BUFFER];
    char buffer2[RX_BUFFER];
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t x = 0;
    uint8_t lastc = 0;
    desiredRPM = 1500;
    while(1){
        if(zTimerReadFlag()){
            int aaa=ic1_getrpm();
            //printf("rpm: %d\r\n desiredRPM: %d\r\n actuator: %d\r\n", ic1_getrpm(), desiredRPM, actuator);
            printf("rpm: %d\r ,desiredRPM: %d\r ,actuator: %d\r\n", aaa, desiredRPM, actuator/1000);
            TickPidControl(aaa);//not working, not increasing actuator when increased load/lowered rpm read
//            int go = 3*actuator;
//            if (go>65534){go=65535;}
            oc1_setduty_plib(actuator);
        }
        if(uart1_rxrdy()){
            char tmp = uart1_rxread();
            if(tmp == '\r'){
                //printf("\r\n desiredRPM: %d\r\n", desiredRPM);
                parseUserCommands(buffer2);
                while(x < lastc){
                    buffer2[x] = '\0';
                    x++;
                }
                x = 0;
                j = 0;
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
