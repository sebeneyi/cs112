/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin College.
 * Date: April 16, 2019
 * Student: Sebene Yi for CS 112 at Calvin College (proj08)
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

template<class Item>

class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty() const;
	bool isFull() const;
	Item peekTop() const;
	void push(const Item& it);
	Item pop();
	
	unsigned getSize();							//proj07
	unsigned getCapacity();						//proj07
	void setCapacity(unsigned newCapacity);		//proj07

protected:
	void makeCopyOf(const Stack& original);
	
private:
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	friend class StackTester;
};

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
template<class Item>
Stack<Item>::Stack(unsigned capacity) {
	if (capacity == 0) {
	       throw StackException("Stack(capacity)", "capacity must be positive!");
	}
   mySize = 0;
   myCapacity = capacity;
   myArray = new Item[capacity];
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template<class Item>
Stack<Item>::Stack(const Stack<Item>& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template<class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
template<class Item>
Stack<Item>::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
template<class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/*
 * checks to see if the stack is empty
 *@param:
 *return: bool
 *Postcondition:
 */
template<class Item>
bool Stack<Item>::isEmpty() const {
	return mySize == 0;
}

/*
 * checks to see if the stack is full
 * @param:
 * return: bool
 * Postcondition:
 */
template<class Item>
bool Stack<Item>::isFull() const {
	return mySize == myCapacity;
}
template<class Item>
Item Stack<Item>::peekTop() const {
    if ( isEmpty() ) {
       throw StackException("peekTop()", "stack is empty!");
    }
	return myArray[mySize-1];
}

/*
 * pushes a item into the array
 * @param:const Item& it
 * return:
 * Postcondition:
 */
template<class Item>
void Stack<Item>::push(const Item& it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full!");
	}
	myArray[mySize] = it;
	mySize++;
}

/*
 * pops the first item in the array
 * and returns it
 * @param:
 * return: Item
 * Postcondition:
 */
template<class Item>
Item Stack<Item>::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty!");
	}
	mySize--;
	return myArray[mySize];
}

/*
 * getter that gets the size
 * @param:
 * return: mySize
 * Postcondition:
 */
template<class Item>
unsigned Stack<Item>::getSize() {
	return mySize;
}

/*
 * getter that gets the capacity
 * @param:
 * return: myCapacity
 * Postcondition:
 */
template<class Item>
unsigned Stack<Item>::getCapacity() {
	return myCapacity;
}

/*
 * sets a new capacity to a stack
 * @param: unsigned newCapacity
 * return:
 * Postcondition: new capacity for the stack
 */
template<class Item>
void Stack<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity != myCapacity) {
		if (newCapacity == 0 or newCapacity < getSize()){
			throw StackException("setCapacity()", "The new capacity is too small. Will lose items!");
		}
		else {
			Item* newArray = new Item[newCapacity];
			for (unsigned i=0; i<mySize; i++) {
				newArray[i] = myArray[i];
			}
			delete [] myArray;
			myArray = newArray;
			myCapacity = newCapacity;
		}
	}
}

#endif

