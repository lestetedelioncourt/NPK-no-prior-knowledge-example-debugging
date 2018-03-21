#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H
#include <iostream>
#include <cassert>
#include "stackADT.h"

using namespace std;

template <typename Type>
struct node{
	Type info;
	node *link;
};

template <typename Type>
class linkedStackType : public stackADT<Type> {
	node<Type> *stackTop;
	void copyStack(const linkedStackType<Type>&);
public:
	linkedStackType();
	linkedStackType(const linkedStackType<Type>&);
	~linkedStackType();
	linkedStackType<Type>& operator=(const linkedStackType<Type>&);
	bool isEmptyStack() const;
	Type top() const;
	void pop();
	void push(const Type&);
	void initialiseStack();
};

template <typename Type>
linkedStackType<Type>::linkedStackType() {
	stackTop = NULL;
}

template <typename Type>
void linkedStackType<Type>::initialiseStack() {
	node<Type> *current;
	current = stackTop;
	while (current != NULL) {
		current = stackTop->link;
		delete stackTop;
		stackTop = current;
	}
}

template <typename Type>
linkedStackType<Type>::~linkedStackType() {
	initialiseStack();
}

template <typename Type>
bool linkedStackType<Type>::isEmptyStack() const {
	return (stackTop == NULL);
}

template <typename Type>
void linkedStackType<Type>::push(const Type &newitem) {
	node<Type> *newNode;
	newNode = new node<Type>;
	newNode->info = newitem;
	newNode->link = stackTop;
	stackTop = newNode;
}

template <typename Type>
Type linkedStackType<Type>::top() const {
	assert(stackTop != NULL);
	return stackTop->info;
}

template <typename Type>
void linkedStackType<Type>::pop() {
	node<Type> *current;
	current = stackTop;
	if (current != NULL) {
		stackTop = current->link;
		delete current;
	}
}

template <typename Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> &rhs) {
	node<Type> *current, *rhscurrent, *last;
	if (stackTop != NULL) {
		initialiseStack();
		stackTop = NULL;
	}
	if (rhs.stackTop == NULL) {
		stackTop = NULL;
	}
	else{
		rhscurrent = rhs.stackTop;
		last = new node<Type>;
		last->info = rhscurrent->info;
		rhscurrent = rhscurrent->link;
		while (rhscurrent != NULL) {
			current = new node<Type>;
			current->info = rhscurrent->info;
			current->link = NULL;
			last->link = current;
			if (stackTop == NULL) {
				stackTop = last;
			}
			rhscurrent = rhscurrent->link;
			last = current;
		}
	}
}	

template <typename Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &rhs) {
	stackTop = NULL;
	copyStack(rhs);
}

template <typename Type>
linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type> &rhs) {
	copyStack(rhs);
	return *this;
}

#endif