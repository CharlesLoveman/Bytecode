#include "StringVM.h"
#include <iostream>

void StringVM::interpret(char* bytecode, int size)
{
	int insPtr = 0;
	while (true) {
		switch (*(bytecode + insPtr))
		{
		case STRING_STR:
		{
			/*int length = std::strlen(bytecode + insPtr + 1);
			char* temp = new char[length + 1];
			memcpy(temp + 1, bytecode + insPtr + 1, length);*/
			//pushObj(bytecode + insPtr + 1, bytecode + size);

			int length = objHeadLen(bytecode + insPtr + 1, bytecode + size);
			push(bytecode + insPtr + 1, length);
			insPtr += length;
			break;
		}
		case STRING_CAT:
		{
			char str1[128];
			char str2[128];
			
			popObj(str2);
			popObj(str1);
			//char* str2 = popObj();
			//char* str1 = popObj();

			int len1 = strlen(str1 + 1);
			int len2 = strlen(str2 + 1);

			char* temp = new char[len1 + len2 + 2];

			memcpy(temp + 1, str1 + 1, len1);
			memcpy(temp + len1 + 1, str2 + 1, len2);

			temp[0] = 0;
			temp[len1 + len2 + 1] = 0;

			pushObj(temp, temp + len1 + len2 + 1);

			delete[] temp;
			break;
		}
		case STRING_OUT:
		{
			char temp[128];
			popObj(temp);
			std::cout << (temp + 1);
			break;
		}
		case STRING_INP:
		{
			char* inp = new char[128];
			inp[0] = 0;
			std::cin >> inp + 1;
			pushObj(inp, inp + 128);
			break;
		}
		default:
			return;
		}
		assert(++insPtr < size);
	}
}
