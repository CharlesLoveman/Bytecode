#ifndef _STRING_VM_H_
#define _STRING_VAM_H_

#include "VM.h"

enum StringInstruction {
	STRING_HALT = 0x00,
	STRING_STR = 0x01,
	STRING_CAT = 0x02,
	STRING_OUT = 0x03,
	STRING_INP = 0x04,
};

class StringVM : public VM {
public:
	void interpret(char* bytecode, int size);
};

#endif // !_STRING_VM_H_
