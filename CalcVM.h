#ifndef _CALC_VM_H_
#define _CALC_VAM_H_

#include "VM.h"

enum CalcInstruction {
	CALC_HALT = 0x00,
	CALC_INT = 0x01,
	CALC_ADD = 0x02,
	CALC_SUB = 0x03,
	CALC_MUL = 0x04,
	CALC_DIV = 0x05,
	CALC_OUT = 0x06,
	CALC_INP = 0x07,
};

class CalcVM : public VM {
public:
	void interpret(char* bytecode, int size);
};

#endif // !_CALC_VM_H_
