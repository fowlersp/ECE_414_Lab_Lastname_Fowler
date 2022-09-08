#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF
#include <xc.h>
#include <inttypes.h>
#include "porta_in.h"
#include "portb_out.h"

int main(){
    const uint8_t const_one = 0x0001;
    uint8_t in, bot_bits;
    uint16_t out;
    porta_in_init();
    portb_out_init();
    while(1){
        in = porta_in_read();
        bot_bits = (in & 0x0F);
        if((in & 0x0010) == 0x0010){
            out = ~(const_one << bot_bits);
        }else{
            out = (const_one << bot_bits);
        }
        portb_out_write(out);
    }
}


