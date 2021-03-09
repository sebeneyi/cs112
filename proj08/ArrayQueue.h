/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (proj08)
 * Date: April 16, 2019
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 * 
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>      // memcpy()
using namespace std;

template<class Item>

class ArrayQueue {
public:

	ArrayQueue(const ArrayQueue& original);
	ArrayQueue(unsigned capacity);
	virtual ~ArrayQueue();
	ArrayQueue& operator=(const ArrayQueue& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;

	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	Item remove();

	void setCapacity(unsigned newCapacity);

protected:
	virtual void makeCopyOf(const ArrayQueue& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirstIndex; // index of oldest item (if any)
	unsigned myLastIndex;  // index of newest item (if any)
	Item*    myArrayPtr;   // dynamic array of items

	friend class ArrayQueueTester;
};


/* default constructor
 * @param: unsigned capacity
 * Postcondition: all private variables are initialized
 */
template<class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
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
template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
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
template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

/* gets the first item at the first index
 * @param:
 * return: first item of the array
 */
template<class Item>
Item ArrayQueue<Item>::getFirst() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("ArrayQueue::getFirst()");
	}
	return myArrayPtr[myFirstIndex];

}

/* gets the last item at the last index
 * @param:
 * return: last item of the array
 */
template<class Item>
Item ArrayQueue<Item>::getLast() const {
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
template<class Item>
void ArrayQueue<Item>::append(const Item& it) {
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
template<class Item>
Item ArrayQueue<Item>::remove() {
	if ( isEmpty() ){
		throw EmptyQueueException("ArrayQueue::remove()");
	}
	Item tempItem = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex + 1) % myCapacity;
	mySize--;
	return tempItem;
}

/* sets the capacity to a new value
 * @param: unsigned newCapacity
 * return:
 * PostCondition: the array now has a new capacity
 */
template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity == 0 or newCapacity < getSize()){
		throw QueueException("ArrayQueue::setCapacity()", "bad new capacity");
	}
	// an array pointer of original and a new one so we can copy
	Item* oldArray = myArrayPtr;
	Item* newArray = new Item[newCapacity];
	// to keep track of the index going through the copy
	unsigned currentIndex = myFirstIndex;
	for (unsigned i = 0; i<getSize(); i++) {
		newArray[i] = oldArray[currentIndex];
		currentIndex = (currentIndex + 1) % myCapacity;
	}

	// after copy allocate the values to the correct variables
	myArrayPtr = newArray;
	delete [] oldArray;

	myCapacity = newCapacity;
	myFirstIndex = 0;
	myLastIndex = mySize - 1;
}

#endif /*ARRAY_QUEUE_H_*/
