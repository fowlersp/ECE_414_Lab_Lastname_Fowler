/*=========================================================
 *main.c
 *Lab 1: Make LED flash and learn about PIC 32
 *
 * Author: Sam Fowler & Name 
 * (code provided by Prof. Nestor)
 ==========================================================*/
/*Clock configuration*/
#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF
#include <xc.h>
#include <inttypes.h>
#define SHAMT 20
void main()
{
 uint32_t count;
 /* Set up all PORTA pins as digital outputs. */
 ANSELA = 0;
 TRISA = 0;
 /* Simple counter. */
 count = 0;
 while (1) {
 // output bottom 3 bits shifted to show progress
 LATA = (count >> SHAMT) & 0x7;
 count++;
 }
}
