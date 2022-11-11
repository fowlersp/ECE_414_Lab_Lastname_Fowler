#include "userCommands.h"
#include "pidControl.h"
#include <stdio.h>

void parseUserCommands(char *command){
    char commandType[2];
    char Type[2];
    uint32_t value;
    sscanf(command, "%s %d %s", commandType, &value, Type);
    //printf("command: %s\r\n", commandType);
    //desiredRPM = value;
    if('s' == commandType[0]){
        printf("command: %s\r\n", commandType);
        desiredRPM = value;
    }else if('p' == commandType[0]){
        setProportionalGain(value);
    }else if('i' == commandType[0]){
        setIntegralGain(value);
    }else if('d' == commandType[0]){
        setDerivativeGain(value);
    }else{
        printf("ERROR: %s\r\n", commandType);
    }
}
