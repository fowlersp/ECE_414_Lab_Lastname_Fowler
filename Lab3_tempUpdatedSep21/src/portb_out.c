#include <xc.h>
#include <inttypes.h>
#include "portb_out.h"
void portb_out_init(){
    ANSELB = 0;
    TRISB = 0;
}

void portb_out_write(uint16_t val){
    uint16_t val1 = val & 0x003F;
    uint16_t val2 = (val << 1) & 0x0180;
    LATB = val1 | val2;
}

void portb_out_write_states(uint16_t state){
    uint16_t val1 = state & 0x0E00;
    uint16_t val2 = (state << 1) & 0x2000;
    //LED = val1 | val2;
    
}
