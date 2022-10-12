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

#define DB_SIZE 100
#define OPERANDS_SIZE 100
#define OPERATORS_SIZE 50

struct CS_data{
    char db[];
    uint32_t operands[];
    char operators[];
    char *write_db;
    char *write_operand;
    char *write_operator;
    char *read_db;
    char db_empty;
    uint32_t *read_operand;
    char operands_empty;
    char *read_operator;
    char operators_empty;
};

enum CS {START, OPP_1, OPP_2}CS_States;

void initCS_data();
void Tick_CSStates();
inline char calculate(char operand_cntr);
inline void clearData();
inline char writeDB(char e);
inline char writeOperands(uint32_t e);
inline void writeOverOperands(uint32_t e);
inline char writeOperators(char operat);
inline char readDB();
inline uint32_t readOperands();
inline char readOperators();
inline uint32_t exponent(uint32_t b, uint32_t e);






