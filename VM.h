#ifndef _VIRTUAL_MACHINE_H_
#define _VIRTUAL_MACHINE_H_

#include <assert.h>
#include <memory>


constexpr int MAX_STACK_SIZE = 128;

class VM {
public:
	virtual void interpret(char* bytecode, int size) = 0;
	~VM();
protected:
	VM();
	template<class T>
	void push(T* value) {
		int size = sizeof(T);
		assert(head + size < MAX_STACK_SIZE);
		memcpy(stack + head, value, size);
		head += size;
	}

	template<class T>
	T pop() {
		head -= sizeof(T);
		assert(head >= 0);
		return (T)*(stack + head);
	}
private:
	char* stack;
	int head;
};

#endif // !_VIRTUAL_MACHINE_H_
