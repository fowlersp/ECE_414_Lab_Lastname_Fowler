/* 
 * File:   calculator_fsm.h
 * Author: sonkinj
 *
 * Created on October 12, 2022, 3:36 PM
 */
#include <inttypes.h>

#ifndef CALCULATOR_FSM_H
#define	CALCULATOR_FSM_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* CALCULATOR_FSM_H */


/*
 * char *db: display buffer of what needs to be displayed
 * uint32_t *operands: contains all of the operands for the calculation
 * char* operators: contains all of the operators to be peformed for a calculation
 * char *read_db: points to which character in the display buffer needs to written to the display next
 * uint32_t *read_operand_ptr: points to which operand the calculation is on
 * char *read_opreators_ptr: points to which operator the calculation is on
 * uint32_t calc_result: the result from the entire calculation
 */



char btn;
char calculation_error;
int32_t result;

#define C 0x0A
#define equ 0x0B
#define plus 0x0C
#define sub 0x0D
#define mult 0x0E
#define div 0x0F

#define DIVBy0 0xFE
#define OVERFLOW 0xFC

enum CS {OPP_1, OPP_2}CS_States;

void Tick_CSStates();
inline char calculate(int32_t operand_1, int32_t operand_2, char operat);






