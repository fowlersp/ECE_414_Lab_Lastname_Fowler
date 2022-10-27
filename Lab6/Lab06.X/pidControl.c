#include "pidControl.h"

void setProportionalGain(uint16_t spg){
    pg = spg;
}

void setIntegralGain(uint16_t sig){
    ig = sig;
}

void setDerivativeGain(uint16_t sdg){
    dg = sdg;
}

void TickPidControl(){
    static uint16_t actualRPMPrev;
    static uint16_t integ;
    uint16_t error;
    uint16_t deriv;
    switch(PID_STATES){
        case PID_INIT:
            actuator = 0;
            actualRPMPrev = 0;
            integ = 0;
            PID_STATES = PID_CTRL;
            break;
        case PID_CTRL:    
            error = desiredRPM - actualRPM;
            deriv = actualRPM - actualRPMPrev;
            integ = integ + error;
            if(integ > integMax){
                integ = integMax;
            }else if(integ < integMin){
                integ = integMin;
            }
            actuator = pg*error + ig*integ - dg*deriv;
            break;
    }
}


