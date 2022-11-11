#include "oc2.h"
#include <xc.h>
#include <plib.h>
    
    void oc1_init_plib(uint16_t duty) {
        OpenTimer2(T2_ON | T2_SOURCE_INT | T2_PS_1_1, 0xffff);
        OpenOC2(OC_ON | OC_TIMER_MODE16| OC_TIMER2_SRC | OC_PWM_FAULT_PIN_DISABLE, 
                duty, duty);  
        // only OC1RS (2rd arg) matters in this example
        //PPSOutput(1, RPB6, OC2);  // map to RPB7 (pin 16)
        PPSOutput(OUT_FN_PPS_OC1,OC2);

    }    
    
    void oc1_setduty_plib(uint16_t duty) {
        SetDCOC1PWM(duty);
    }

