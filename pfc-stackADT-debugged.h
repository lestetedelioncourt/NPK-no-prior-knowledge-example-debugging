#ifndef STACKADT_H
#define STACKADT_H
#include <iostream>
using namespace std;

template <typename Type>
class stackADT {
	virtual void initialiseStack() = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
	virtual void push(const Type&) = 0;
	virtual bool isEmptyStack() const = 0;
};

#endif