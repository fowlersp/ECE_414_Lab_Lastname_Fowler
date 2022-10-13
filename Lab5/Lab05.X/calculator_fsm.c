#include "calculator_fsm.h"
#include <string.h>

void Tick_CSStates(){
    static uint32_t operand_1;
    static uint32_t operand_2;
    static char operat;
    switch(CS_States){
        case OPP_1:
            if(btn > equ){
                operat = btn;
                CS_States = OPP_2;
            }else if(btn < C){
                operand_1 = operand_1*10 + btn;
                CS_States = OPP_1;
            }else if(btn == 0x0A){
                CS_States = OPP_1;
            }
        break;

        case OPP_2:
            if(btn == C){
                CS_States = OPP_1;
            }else if(btn < C){
                operand_2 = operand_2*10 + btn;
                CS_States = OPP_2;
            }else if(btn == equ){
                calculation_error = calculate(operand_1, operand_2, operat);
                CS_States = OPP_2;
            }else if(btn > equ){
                calculation_error = calculate(operand_1, operand_2, operat);
                CS_States = OPP_2;
            }
        break;
    }
}

/*
 return codes:
 * 0xFE: DIV/0
 * 0xFC: Result overflow
 */
inline char calculate(uint32_t operand_1, uint32_t operand_2, char operat){
    switch(operat){
        case plus:
            result = operand_1 + operand_2;
            if(result > 0xF0000000){
                return OVERFLOW;
            }
        break;
        
        case sub:
            result = operand_1 - operand_2;
        break;
        
        case mult:
            result = operand_1 * operand_2;
            if(result > 0xF0000000){
                return OVERFLOW;
            }
        break;
        
        case div:            
            if(operand_2 == 0x00000000){
                return DIVBy0;
            }else{
                result = operand_1 / operand_2;
            }
        break;    
    }
    return 0x00;
}