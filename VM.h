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

	void push(void* value, int size) {
		assert(head + size < MAX_STACK_SIZE);
		memcpy(stack + head, value, size);
		head += size;
	}

	template<class T>
	void push(T* value) {
		push(value, sizeof(T));
	}

	void pushObj(char* value, char* end) {
		push(value, objHeadLen(value, end));
	}

	template<class T>
	T pop(int size) {
		head -= size;
		assert(head >= 0);
		return (T) *(stack + head);
	}

	template<class T>
	T pop() {
		return pop<T>(sizeof(T));
	}


	void popObj(char* dest) {
		//return pop<char*>(objTailLen(stack + head - 1, stack));
		int size = objTailLen(stack + head - 1, stack);
		head -= size;
		assert(head >= 0);
		memcpy(dest, stack + head, size);
	}



	int Len() {
		objTailLen(stack + head - 1, stack);
	}

	int objTailLen(char* end, char* start) {
		assert(*end == NULL);
		char* i = end - 1;
		while (true) {
			assert(i >= start);
			if (*i == NULL) {
				return (int)(end)-(int)(i) + 1;
			}
			--i;
		}
	}

	int objHeadLen(char* start, char* end) {
		assert(*start == NULL);
		char* i = start + 1;
		while (true) {
			assert(i <= end);
			if (*i == NULL) {
				return (int)(i)-(int)(start)+1;
			}
			++i;
		}
	}

private:
	char* stack;
	int head;
};

#endif // !_VIRTUAL_MACHINE_H_
