#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"

void portb_out_init(){
    ANSELB = 0;
    TRISB = 0;
}

void portb_out_write(uint16_t val){
    uint16_t val1 = val & 0x003F;
    uint16_t val2 = (val << 1) & 0x0040;
    LATB = val1 | val2;
}
