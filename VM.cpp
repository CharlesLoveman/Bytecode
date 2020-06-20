#include "VM.h"

#include <memory>

VM::~VM()
{
    free(stack);
}

VM::VM()
{
    head = 0;
    stack = (char*)malloc(MAX_STACK_SIZE);
}
