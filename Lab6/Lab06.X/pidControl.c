#include "pidControl.h"

int rpm;

void setProportionalGain(uint16_t spg){
    pg = spg;
}

void setIntegralGain(uint16_t sig){
    ig = sig;
}

void setDerivativeGain(uint16_t sdg){
    dg = sdg;
}

void TickPidControl(uint16_t rpm){
    static uint16_t actualRPMPrev;
    float actuator_f;
    static int16_t integ;
    int16_t error;
    int16_t deriv;
    switch(PID_STATES){
        case PID_INIT:
            actuator = 0;
            actualRPMPrev = 0;
            integ = 0;
            PID_STATES = PID_CTRL;
            break;
        case PID_CTRL:
            actualRPM = rpm;
            error = desiredRPM - actualRPM;
            deriv = actualRPM - actualRPMPrev;
            integ = integ + error;
            if(integ > integMax){
                integ = integMax;
            }else if(integ < integMin){
                integ = integMin;
            }
            actuator_f = ((float) pg* (float) error) + ((float)ig * (float)integ) - ((float)dg * (float) deriv); // + ig*integ - dg*deriv;
            if (actuator_f >= 65335.0){
                actuator = 65335;
            }else if(actuator_f <= 0){
                actuator = 0;
            }else{
                actuator = (uint16_t) actuator_f;
            }
            //actuator = -pg*error - ig*integ + dg*deriv;
            //printf("error: %d\r ,integ: %d\r ,deriv: %d\r\n", error, integ, deriv);
            actualRPMPrev = actualRPM;
            PID_STATES = PID_CTRL;
            break;
    }
}


