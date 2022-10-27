#include "userCommands.h"
#include "pidControl.h"
#include <stdio.h>

void parseUserCommands(char *command){
    char commandType;
    uint32_t value;
    sscanf(command, "%c %d", commandType, value);
    if('s' == commandType){
        desiredRPM = value;
    }else if('p' == commandType){
        setProportionalGain(value);
    }else if('i' == commandType){
        setIntegralGain(value);
    }else if('d' == commandType){
        setDerivativeGain(value);
    }
}
