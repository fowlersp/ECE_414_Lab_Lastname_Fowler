/* 
 * File:   testmain.c
 * Author: fowlersp
 *
 * Created on September 29, 2022, 10:05 AM
 */

/* Clock configuration */
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF

#include <stdio.h>
#include <stdlib.h>
#include "ztimer.h"


#define NUM_ITERATIONS 1000000
#define NUM_REPS 10
#define PERIOD_T 1000
#define BAUDRATE 9600
/*
 * 
 */

void test_uint8_mult()
{
    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
    }
}
void test_uint16_mult()
{
    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
    }
}
void test_uint32_mult()
{
    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
    }
}
void test_uint64_mult()
{
    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
    }
}

void test_uint8_div()
{
    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}
void test_uint16_div()
{
    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}
void test_uint32_div()
{
    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}
void test_uint64_div()
{
    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}


void test_uint8_subtract()
{
    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}
void test_uint16_subtract()
{
    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}
void test_uint32_subtract()
{
    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}
void test_uint64_subtract()
{
    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

void test_uint8_add()
{
    uint32_t i;
    uint8_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}
void test_uint16_add()
{
    uint32_t i;
    uint16_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_uint32_add()
{
    uint32_t i;
    uint32_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_uint64_add()
{
    uint32_t i;
    uint64_t i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_float_add(){
    uint32_t i;
    float i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_float_sub(){
    uint32_t i;
    float i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

void test_float_mult(){
    uint32_t i;
    float i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
    }
}

void test_float_div(){
    uint32_t i;
    float i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}

void test_double_add(){
    uint32_t i;
    double i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
        i3 = i1+i2;
    }
}

void test_double_sub(){
    uint32_t i;
    double i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
        i3 = i1-i2;
    }
}

void test_double_mult(){
    uint32_t i;
    double i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
        i3 = i1*i2;
    }
}

void test_double_div(){
    uint32_t i;
    double i1, i2, i3;
    i1 = 15;
    i2 = 26;
    for (i=0; i<NUM_ITERATIONS; i++){
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
        i3 = i1/i2;
    }
}

int main(int argc, char** argv) {

    uint32_t loopcount = 1;
    
        
    printf("/n /n");
            
    uint32_t t1, t2;
    zTimerSet(PERIOD_T);
    uart1_init(BAUDRATE);
    printf("Performance Summary: Time per operation statistics\r\n");
    zTimerOn();
    t1 = zTimerReadms();
    test_uint8_mult();
    t2 = zTimerReadms();
    printf("UINT8 MULT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_uint16_mult();
    t2 = zTimerReadms();
    printf("UINT16 MULT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_uint32_mult();
    t2 = zTimerReadms();
    printf("UINT32 MULT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
       
    t1 = zTimerReadms();
    test_uint64_mult();
    t2 = zTimerReadms();
    printf("UINT64 MULT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
        
    t1 = zTimerReadms();
    test_uint8_div();
    t2 = zTimerReadms();
    printf("UINT8 DIVIDE: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_uint16_div();
    t2 = zTimerReadms();
    printf("UINT16 DIVIDE: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
            
    t1 = zTimerReadms();
    test_uint32_div();
    t2 = zTimerReadms();
    printf("UINT32 DIVIDE: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
            
    t1 = zTimerReadms();
    test_uint64_div();
    t2 = zTimerReadms();
    printf("UINT64 DIVIDE: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_uint8_subtract();
    t2 = zTimerReadms();
    printf("UINT8 SUBTRACT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_uint16_subtract();
    t2 = zTimerReadms();
    printf("UINT16 SUBTRACT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
            
    t1 = zTimerReadms();
    test_uint32_subtract();
    t2 = zTimerReadms();
    printf("UINT32 SUBTRACT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
            
    t1 = zTimerReadms();
    test_uint64_subtract();
    t2 = zTimerReadms();
    printf("UINT64 SUBTRACT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
     
    t1 = zTimerReadms();
    test_float_sub();
    t2 = zTimerReadms();
    printf("FLOAT SUBTRACT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_double_sub();
    t2 = zTimerReadms();
    printf("DOUBLE SUBTRACT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_float_mult();
    t2 = zTimerReadms();
    printf("FLOAT MULT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_double_mult();
    t2 = zTimerReadms();
    printf("DOUBLE MULT: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_float_div();
    t2 = zTimerReadms();
    printf("FLOAT DIV: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_double_div();
    t2 = zTimerReadms();
    printf("DOUBLE DIV: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    
    
    t1 = zTimerReadms();
    test_uint8_add();
    t2 = zTimerReadms();
    printf("UINT8 ADD: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_uint16_add();
    t2 = zTimerReadms();
    printf("UINT16 ADD: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
            
    t1 = zTimerReadms();
    test_uint32_add();
    t2 = zTimerReadms();
    printf("UINT32 ADD: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
            
    t1 = zTimerReadms();
    test_uint64_add();
    t2 = zTimerReadms();
    printf("UINT64 ADD: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
     
    t1 = zTimerReadms();
    test_float_add();
    t2 = zTimerReadms();
    printf("FLOAT ADD: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    t1 = zTimerReadms();
    test_double_add();
    t2 = zTimerReadms();
    printf("DOUBLE ADD: %.06f us per operation\r\n", ((double)(t2 - t1)) / ((double) NUM_ITERATIONS) / (double) NUM_REPS*1000.0);
    zTimerSet(0);//why not
    
    
    //loopcount=loopcount+6;
    //printf("Loop count %.06f \r\n", loopcount);
    
    return (EXIT_SUCCESS);
}

