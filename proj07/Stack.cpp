/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Date: March 28, 2019
 * Student: Sebene Yi for CS 112 at Calvin College (proj07)
 */

#include "Stack.h"

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
Stack::Stack(unsigned capacity) {
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
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
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
Stack::~Stack() {
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
Stack& Stack::operator=(const Stack& original) {
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
bool Stack::isEmpty() const {
	return mySize == 0;
}

/*
 * checks to see if the stack is full
 * @param:
 * return: bool
 * Postcondition:
 */
bool Stack::isFull() const {
	return mySize == myCapacity;
}

Item Stack::peekTop() const {
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
void Stack::push(const Item& it) {
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
Item Stack::pop() {
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
unsigned Stack::getSize() {
	return mySize;
}

/*
 * getter that gets the capacity
 * @param:
 * return: myCapacity
 * Postcondition:
 */
unsigned Stack::getCapacity() {
	return myCapacity;
}

/*
 * sets a new capacity to a stack
 * @param: unsigned newCapacity
 * return:
 * Postcondition:
 */
void Stack::setCapacity(unsigned newCapacity) {
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
