/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (lab08)
 * Date: April 03, 2019
 */

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
using namespace std;

/* default constructor
 * @param: unsigned capacity
 * Postcondition: all private variables are initialized
 */
ArrayQueue::ArrayQueue(unsigned capacity) {
	if (capacity < 1) {
		throw QueueException("constructor", "capacity is negative!");
	}
	myCapacity = capacity;
	mySize = myFirstIndex = 0;
	myLastIndex = capacity - 1;
	myArrayPtr = new Item[capacity];
}


/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
ArrayQueue::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
unsigned ArrayQueue::getSize() const {
	return mySize;
}

/* gets the first item at the first index
 * @param:
 * return: first item of the array
 */
Item ArrayQueue::getFirst() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("ArrayQueue::getFirst()");
	}
	return myArrayPtr[myFirstIndex];

}

/* gets the last item at the last index
 * @param:
 * return: last item of the array
 */
Item ArrayQueue::getLast() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("ArrayQueue::getLast()");
	}
	return myArrayPtr[myLastIndex];

}

/* appends an item to the last of the array
 * @param: const Item& it
 * return:
 * Postcondition: new item added as the last
 */
void ArrayQueue::append(const Item& it) {
	if ( isFull() ){
		throw FullQueueException("ArrayQueue::append()");
	}
	myLastIndex = (myLastIndex + 1) % myCapacity;
	myArrayPtr[myLastIndex] = it;
	mySize++;
}

/* removes an item
 * @param:
 * return: Item
 * Postcondition: on Item removed and size - 1
 */
Item ArrayQueue::remove() {
	if ( isEmpty() ){
		throw EmptyQueueException("ArrayQueue::remove()");
	}
	Item tempItem = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex + 1) % myCapacity;
	mySize--;
	return tempItem;
}
