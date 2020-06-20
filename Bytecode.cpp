// Bytecode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "VM.h"
#include "CalcVM.h"
#include "StringVM.h"

int main()
{
    VM* myVM = new StringVM();
    
    char* bytecode = new char[5];

    bytecode[0] = StringInstruction::STRING_INP;

    bytecode[1] = StringInstruction::STRING_INP;

    bytecode[2] = StringInstruction::STRING_CAT;

    bytecode[3] = StringInstruction::STRING_OUT;

    bytecode[4] = StringInstruction::STRING_HALT;

    myVM->interpret(bytecode, 5);

    delete myVM;
    delete[] bytecode;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
