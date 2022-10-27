
#include "config_clk.h"
#include "ic1.h"
#include "oc1_plib.h"
#include "uart1.h"
#include "ztimer4.h"
#include "userCommands.h"

void main(){
    oc1_init_plib(0);
    oc1_setduty_plib(0xFFFF);
}