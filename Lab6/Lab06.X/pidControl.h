/* 
 * File:   pidControl.h
 * Author: sonkinj
 *
 * Created on October 27, 2022, 8:36 AM
 */

#ifndef PIDCONTROL_H
#define	PIDCONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif
    #include <inttypes.h>

    int16_t integ;
    int16_t error;
    int16_t deriv;
        
    uint16_t pg, ig, dg;
    uint32_t desiredRPM, actualRPM;
    //int16_t integMax, integMin;
    uint16_t actuator;
    float actuator_f;
    
    int16_t integMax = 1000;
    int16_t integMin = -1000;
    
    enum PID {PID_INIT, PID_CTRL}PID_STATES;
    
    void setProportionalGain(uint16_t spg);
    void setIntegralGain(uint16_t sig);
    void setDerivativeGain(uint16_t sdg);
    void TickPidControl(uint16_t rpm);


#ifdef	__cplusplus
}
#endif

#endif	/* PIDCONTROL_H */

