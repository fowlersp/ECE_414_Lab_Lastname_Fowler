#include "config_clk.h"
#include "ic1.h"
#include "oc1_plib.h"
#include "uart1.h"
#include "ztimer4.h"
#include <stdio.h>
//#include "userCommands.h"

#define RX_BUFFER 100

void main(){
    oc1_init_plib(0);
    oc1_setduty_plib(0xFFFF);
    ic1_init();
    uart1_init(9600);
    zTimerSet(100);
    zTimerOn();
    INTEnableSystemMultiVectoredInt();
    while(1){
        if(zTimerReadFlag()){
            printf("%d\r\n", ic1_getrpm());
        }
    }
    /*
    char buffer[RX_BUFFER];
    uint8_t i = 0;
    while(1){
        if(uart1_rxrdy()){
            buffer[i] = (uint8_t) ic1_getrpm();
            printf("%d", buffer[i]);
            i++;
        }
        if(i > 0 && uart1_txrdy()){
            i--;
            //uart1_txwrite_str("hello");
            uart1_txwrite(buffer[i]);
           
        }
     * */
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
