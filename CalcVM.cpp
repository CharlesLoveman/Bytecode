#include "CalcVM.h"

#include <iostream>

void CalcVM::interpret(char* bytecode, int size)
{
	int insPtr = 0;
	while (true) {
		switch (*(bytecode + insPtr))
		{
		case CalcInstruction::CALC_INT:
			push<int>((int*)(bytecode + insPtr + 1));
			insPtr += sizeof(int);
			break;
		case CalcInstruction::CALC_ADD:
		{
			int temp = pop<int>() + pop<int>();
			push<int>(&temp);
			break;
		}
		case CalcInstruction::CALC_SUB:
		{
			int temp = pop<int>();
			temp = pop<int>() - temp;
			push<int>(&temp);
			break;
		}
		case CalcInstruction::CALC_MUL:
		{
			int temp = pop<int>() * pop<int>();
			push<int>(&temp);
			break;
		}
		case CalcInstruction::CALC_DIV:
		{
			int temp = pop<int>();
			temp = pop<int>() / temp;
			push<int>(&temp);
			break;
		}
		case CalcInstruction::CALC_OUT:
			std::cout << pop<int>();
			break;
		case CalcInstruction::CALC_INP:
		{
			int input;
			std::cin >> input;
			push<int>(&input);
			break;
		}

		default:
			return;
		}
		assert(++insPtr < size);
	}
}
