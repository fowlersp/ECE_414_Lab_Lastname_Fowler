#include "RIMS.h"

volatile unsigned char TimerFlag = 0;

void TimerISR(){
    TimerFlag = 1;
}

enum PONG_States {PONG_START, PONG_SERVE, PONG_MOVELEDL, PONG_MOVELEDR, PONG_LOSEL, PONG_LOSER} PONG_States;

void Tick_PONGStates(){
    
}