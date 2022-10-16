#include "calculator_fsm.h"
#include <string.h>

uint32_t pval;
char calc_error[30];

void Tick_CSStates(){
    static uint32_t operand_1;
    static uint32_t operand_2;
    static char operat;
    switch(CS_States){
        case OPP_1:
            if(btn > equ){
                if(calculation_error != 0){
                    char str1[30];
                    sprintf(str1,"%d", 0);
                    char str2[30];
                    sprintf(str2,"%s", calc_error);
                    ts_write(str1, str2);
                    pval = 0;
                    calculation_error = 0;
                }else{
                    char str1[30];
                    sprintf(str1,"%d", 0);
                    char str2[30];
                    sprintf(str2,"%d", pval);
                    ts_write(str1, str2);
                    pval = 0;
                }
                operat = btn;
                CS_States = OPP_2;
            }else if(btn < C){
                operand_1 = operand_1*10 + btn;
                if(calculation_error != 0){
                    char str1[30];
                    sprintf(str1,"%d", operand_1);
                    char str2[30];
                    sprintf(str2,"%s", calc_error);
                    ts_write(str1, str2);
                    pval = operand_1;
                    calculation_error = 0;
                }else{
                    char str1[30];
                    sprintf(str1,"%d", operand_1);
                    char str2[30];
                    sprintf(str2,"%d", pval);
                    ts_write(str1, str2);
                    pval = operand_1;
                }
                CS_States = OPP_1;
            }else if(btn == 0x0A){
                if(calculation_error != 0){
                    char str1[30];
                    sprintf(str1,"%d", 0);
                    char str2[30];
                    sprintf(str2,"%s", calc_error);
                    ts_write(str1, str2);
                    pval = 0;
                    calculation_error = 0;
                }else{
                    char str1[30];
                    sprintf(str1,"%d", 0);
                    char str2[30];
                    sprintf(str2,"%d", pval);
                    ts_write(str1, str2);
                    pval = 0;
                }
                operand_1 = 0;
                CS_States = OPP_1;
            }
        break;

        case OPP_2:
            if(btn == C){
                char str1[30];
                sprintf(str1,"%d", 0);
                char str2[30];
                sprintf(str2,"%d", pval);
                ts_write(str1, str2);
                pval = 0;
                operand_1 = 0;
                operand_2 = 0;
                CS_States = OPP_1;
            }else if(btn < C){
                operand_2 = operand_2*10 + btn;
                char str1[30];
                sprintf(str1,"%d", operand_2);
                char str2[30];
                sprintf(str2,"%d", pval);
                ts_write(str1, str2);
                pval = operand_2;
                CS_States = OPP_2;
            }else if(btn == equ){
                calculation_error = calculate(operand_1, operand_2, operat);
                operand_1 = 0;
                operand_2 = 0;
                operat = 0;
                CS_States = OPP_1;
            }else if(btn > equ){
                calculation_error = calculate(operand_1, operand_2, operat);
                if(calculation_error != 0){
                    char str1[30];
                    sprintf(str1,"%s", calc_error);
                    char str2[30];
                    sprintf(str2,"%s", calc_error);
                    ts_write(str1, str2);
                    operand_1 = 0;
                    operand_2 = 0;
                    operat = 0;
                    CS_States = OPP_1;
                }else{
                    char str1[30];
                    sprintf(str1,"%d", result);
                    char str2[30];
                    sprintf(str2,"%d", pval);
                    ts_write(str1, str2);
                    pval = result;
                    operand_1 = result;
                    operand_2 = 0;
                    operat = btn;
                    CS_States = OPP_2;
                }
                
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
            if(result > 0x80000000){
                char str1[30];
                sprintf(str1,"%s", "OVERFLOW");
                char str2[30];
                sprintf(str2,"%d", pval);
                ts_write(str1, str2);
                sprintf(calc_error,"%s", "OVERFLOW");
                return OVERFLOW;
            }else{
                char str1[30];
                sprintf(str1,"%d", result);
                char str2[30];
                sprintf(str2,"%d", pval);
                ts_write(str1, str2);
                pval = result;
            }
        break;
        
        case sub:
            result = operand_1 - operand_2;
            char str1[30];
            sprintf(str1,"%d", result);
            char str2[30];
            sprintf(str2,"%d", pval);
            ts_write(str1, str2);
            pval = result;
        break;
        
        case mult:
            result = operand_1 * operand_2;
            if(result > 0x80000000){
                char str1[30];
                sprintf(str1,"%s", "OVERFLOW");
                char str2[30];
                sprintf(str2,"%d", pval);
                ts_write(str1, str2);
                sprintf(calc_error,"%s", "OVERFLOW");
                return OVERFLOW;
            }else{
                char str1[30];
                sprintf(str1,"%d", result);
                char str2[30];
                sprintf(str2,"%d", pval);
                ts_write(str1, str2);
                pval = result;
            }
        break;
        
        case div:            
            if(operand_2 == 0x00000000){
                char str1[30];
                sprintf(str1,"%s", "DIVBy0");
                char str2[30];
                sprintf(str2,"%d", pval);
                ts_write(str1, str2);
                sprintf(calc_error,"%s", "DIVBy0");
                return DIVBy0;
            }else{
                result = operand_1 / operand_2;
                char str1[30];
                sprintf(str1,"%d", result);
                char str2[30];
                sprintf(str2,"%d", pval);
                ts_write(str1, str2);
                pval = result;
            }
        break;    
    }
    return 0x00;
}