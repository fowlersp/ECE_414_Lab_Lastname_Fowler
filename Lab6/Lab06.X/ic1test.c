/* 
 * File:   ic1test.c
 * Author: nestorj
 *
 * Test program for input capture module
 * Use with a UART to report period measured by input capture
 * and equivalent RPM
 * 
 */

#include <xc.h>
#include <plib.h>
#include <inttypes.h>
#include <stdio.h>

#include "config_clk.h"
#include "ztimer4.h"
#include "uart1.h"
#include "ic1.h"

int main() {
    uint16_t period, lastperiod;
    uint8_t buffer [20];
    zTimerOn();
    zTimerSet(1000);
    uart1_init(9600);
    uart1_txwrite_str("Beginning IC1 test\n\r");
    ic1_init();
    INTEnableSystemMultiVectoredInt();
    while (1) {
        if (zTimerReadFlag()) {
            //period = ic1_getperiod();
            //printf("period: %6d   rpm: %6d\r\n", period, ic1_getrpm());
            //if (period != lastperiod) {
            //    lastperiod = period;
            //}
            period = ic1_getperiod();
            printf("period: %6d  rpm: %6d\r\n", period, ic1_ticks2rpm(period));
        }

    }

}
