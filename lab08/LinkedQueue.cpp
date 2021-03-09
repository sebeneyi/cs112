/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (lab08)
 * Date: April 03, 2019
 */

#include "LinkedQueue.h"

/* default constructor
 * @param:
 * Postcondition: the variables are initialized
 */
LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirstPtr = myLastPtr = NULL;
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = NULL;
	} else {
		myFirstPtr = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != NULL) {
			temp1->myNextPtr = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = NULL;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

/* gets the first item at first node
 * @param:
 * return: Item
 */
Item LinkedQueue::getFirst() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("LinkedQueue::getFirst()");
	}
	return myFirstPtr -> myItem;
}

/* gets the last item at the last node
 * @param:
 * return: Item
 */
Item LinkedQueue::getLast() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("LinkedQueue::getLast()");
	}
	return myLastPtr -> myItem;
}

/* adds a node to the end of the queue
 * @param: const Item& it
 * return:
 * Postcondition: size + 1, an added node to the end
 */
void LinkedQueue::append(const Item& it) {
	try {
		Node* nPtr = new Node(it, NULL);
		if ( isEmpty() ) {
			myFirstPtr = nPtr;
		}	 else {
			myLastPtr->myNextPtr = nPtr;
		}
		myLastPtr = nPtr;
		mySize++;
	} catch(const bad_alloc& ba) {
		throw FullQueueException("LinkedQueue::append()");
	}
}

/* removes an node from the Linked queue
 * @param:
 * return: Item
 * Postcondition: size - 1, one node removed
 */
Item LinkedQueue::remove() {
	if ( isEmpty() ) {
		throw EmptyQueueException("LinkedQueue::remove()");
	}
	Item tempItem = myFirstPtr -> myItem;
	Node* delPtr = myFirstPtr;
	myFirstPtr = myFirstPtr -> myNextPtr;
	delPtr -> myNextPtr = NULL;
	delete delPtr;
	mySize--;
	return tempItem;
}
