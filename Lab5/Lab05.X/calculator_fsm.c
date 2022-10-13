#include "calculator_fsm.h"
#include <string.h>

struct CS_data;
char btn;
char calculation_error;

void initCS_data(){
    CS_data.db[DB_SIZE];
    CS_data.operands[OPERANDS_SIZE];
    CS_data.operators[OPERATORS_SIZE];
    CS_data.write_db = CS_data.db;
    CS_data.write_operand = CS_data.operands;
    CS_data.write_operator = CS_data.operators;
    CS_data.read_db = CS_data.db;
    CS_data.db_empty = 1;
    CS_data.read_operand = CS_data.operands;
    CS_data.operands_empty = 1;
    CS_data.read_operator = CS_data.operators;
    CS_data.operators_empty = 1;
    return;
}

void Tick_CSStates(){
    static char operand_cntr;
    switch(CS_States){
        case OPP_1:
            if(btn > 0x0B){
                while(writeOperators(btn) == 0xFF){}
                CS_States = OPP_2;
                operand_cntr = 0;
            }else if(btn < 0x0A){
                uint32_t val = exponent(10, operand_cntr);
                if(operand_cntr > 0){
                    writeOverOperands(val);
                }else{
                    while(writeOperands(val) == 0xFF){}
                }
                operand_cntr++;
                while(writeDB(btn) == 0xFF){}
                CS_States = OPP_1;
            }else if(btn == 0x0A){
                clearData();
                CS_States = OPP_1;
            }
        break;

        case OPP_2:
            if(btn == 0x0A){
                clearData();
                CS_States = OPP_1;
            }else if(btn < 0x0A){
                uint32_t val = exponent(10, operand_cntr);
                if(operand_cntr > 0){
                    writeOverOperands(val);
                }else{
                    while(writeOperands(val) == 0xFF){}
                }
                operand_cntr++;
                while(writeDB(btn) == 0xFF){}
                CS_States = OPP_2;
            }else if(btn == 0x0B){
                calculation_error = calculate(operand_cntr);
                CS_States = OPP_2;
                operand_cntr = 0;
            }else if(btn > 0x0B){
                calculation_error = calculate(operand_cntr);
                while(writeOperators(btn) == 0xFF){}
                CS_States = OPP_2;
                operand_cntr = 0;
            }
        break;
    }
}

/*
 return codes:
 * 0xFF: unable to read operator or operands
 * 0xFE: DIV/0
 * 0xFD: unable to writeOperands(bufferOverflow)
 */
inline char calculate(char operand_cntr){
    char operat = readOperators();
    uint32_t operand_1 = readOperands();
    uint32_t operand_2 = readOperands();
    uint32_t result = 0;
    if(operat == 0xFF || operand_1 == 0xFF || operand_2 == 0xFF){
        return 0xFF;
    }
    switch(operat){
        case 0x0C:
            result = operand_1 + operand_2;
        break;
        
        case 0x0D:
            result = operand_1 - operand_2;
        break;
        
        case 0x0E:
            result = operand_1 * operand_2;
        break;
        
        case 0x0F:            
            if(operand_2 == 0x00000000){
                return 0xFE;
            }else{
                result = operand_1 / operand_2;
            }
        break;    
    }
    if(writeOperands(result) == 0xFF){
        return 0xFD;
    }
    
    while(result != 0){
        if(writeDB(result/exponent(10, operand_cntr) % 10) == 0xFF){
            return 0xFC;
        }
        operand_cntr--;
    }
    return 0x00;
}

inline void clearData(){
    memset(CS_data.db, 0, DB_SIZE*sizeof(char));
    memset(CS_data.operands, 0, OPERANDS_SIZE*sizeof(uint32_t));
    memset(CS_data.operators, 0, OPERATORS_SIZE*sizeof(char));
    CS_data.write_db = CS_data.db;
    CS_data.write_operand = CS_data.operands;
    CS_data.write_operator = CS_data.operators;
    CS_data.read_db = CS_data.db;
    CS_data.read_operand = CS_data.operands;
    CS_data.read_operator = CS_data.operators;
}

inline char writeDB(char e){
    if(CS_data.write_db >= CS_data.db + DB_SIZE*sizeof(char*)){
        return 0xFF;
    }
    CS_data.db_empty ? CS_data.db_empty = 0 : CS_data.db_empty = 0;
    *CS_data.write_db = e;
    CS_data.write_db++;
    return 0x00;
}

inline char writeOperands(uint32_t e){
    if(CS_data.write_operand >= CS_data.operands + OPERANDS_SIZE*sizeof(uint32_t*)){
        return 0xFF;
    }
    CS_data.operands_empty ? CS_data.operands_empty = 0 : CS_data.operands_empty = 0;
    CS_data.write_operand = e;
    CS_data.write_operand++;
    return 0x00;
}

inline void writeOverOperands(uint32_t e){
    CS_data.write_operand--;
    CS_data.operands_empty ? CS_data.operands_empty = 0 : CS_data.operands_empty = 0;
    CS_data.write_operand = e;
    CS_data.write_operand++;
    return 0x00;
}

inline char writeOperators(char operat){
    if(CS_data.write_operator >= CS_data.operators + OPERATORS_SIZE*sizeof(char*)){
        return 0xFF;
    }
    CS_data.operators_empty ? CS_data.operators_empty = 0 : CS_data.operators_empty = 0;
    CS_data.write_operator = operat;
    CS_data.write_operator++;
    return 0x00;
}

inline char readDB(){
    if(CS_data.db_empty){
        return 0xFF;
    }
    char result = CS_data.read_db;
    CS_data.read_db++;
    return result;    
}

inline uint32_t readOperands(){
    if(CS_data.operands_empty){
        return 0xFF;
    }
    char result = CS_data.read_operand;
    CS_data.read_operand++;
    return result;
}

inline char readOperators(){
    if(CS_data.operators_empty){
        return 0xFF;
    }
    char result = CS_data.read_operator;
    CS_data.read_operator++;
    return result;
}

inline uint32_t exponent(uint32_t b, uint32_t e){
    if(e < 0){
        return 0xFFFFFFFF;
    }
    uint32_t result = 1;
    for(int i = 0; i < e; i++){
        result = result*b;
    }
    return result;
}

