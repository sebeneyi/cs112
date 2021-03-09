/*
 * List.cpp defines List class methods.
 *  Created on: Mar 5, 2019
 *  Author: Sebene Yi (ssy3) at Calvin College for CS 112 lab05
 */

#include "List.h"
#include <stdexcept>

/*
 * default constructor initializing default values
 * @param:
 * return:
 */
List::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

/*
 * Node default constructor initializing default values to nodes
 * @param:
 * return:
 */
List::Node::Node() {
		myItem = Item();
		myNext = NULL;
}

/*
 * Node explicit constructor initializing given values to nodes
 * @param:
 * return:
 */
List::Node::Node(Item it, Node * next) {
	myItem = it;
	myNext = next;
}

/*
 * adds Item it to the list
 * @param: Item it
 * return: a new list
 */
void List::append(const Item& it) {
	List::Node* n1 = new List::Node(it, NULL);
	if (mySize == 0) {
		mySize = 1;
		myLast = n1;
		myFirst = n1;
	}
	else {
		myLast->myNext = n1;
		mySize += 1;

	}
	myLast = n1;
}

/*
 * gets and returns mySize
 * @param:
 * return: unsigned mySize
 */
unsigned List::getSize() const {
	return mySize;
}

/*
 * gets the first node in a list
 * @param:
 * return: Item with a node whose address is in myFirst
 */
Item List::getFirst() const {
	if (mySize < 0 or myFirst == NULL) {
		throw underflow_error("Parameters are negative and null!");
	}
	return myFirst -> myItem;
}

/*
 * gets the last node in a list
 * @param:
 * return: Item with a node whose address is in myLast
 */
Item List::getLast() const {
	if (mySize < 0 or myFirst == NULL) {
		throw underflow_error("Parameters are negative and null!");
	}
	return myLast -> myItem;
}

/*
 * destructor to reclaim dynamic memory
 * @param:
 * return:
 */
List::~List() {
   delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
   myFirst = myLast = NULL; // clear myFirst and myLast (optional)
   mySize = 0;              // clear mySize (optional)
}

/*
 * destructor to reclaim dynamic memory
 * @param:
 * return:
 */
List::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item "
//	             << myItem << endl;
     delete myNext;       // delete the next node, invoking ~Node() in it
                          // (does nothing if myNext == NULL)
  }

/*
 * copy constructor
 * @param: const List&
 * return:
 */
List::List(const List& original) {
	myFirst = myLast = NULL; //  set pointers
	mySize = 0; //   and size to 'empty' values
	Node* oPtr = original.myFirst; //  start at the first node
	while (oPtr != NULL) {
		//  while there are nodes to copy:
		append(oPtr->myItem); //   append the item in that node
		oPtr = oPtr->myNext; //   advance to next node
	}
}

/*
 * defining = operator
 * @param: const List&
 * return: List&
 */
List& List::operator=(const List& original) {
	if (&original != this) {
		delete myFirst;
		myFirst = myLast = NULL; //  set pointers
		mySize = 0; //   and size to 'empty' values
		Node* nPtr = original.myFirst;
		while (nPtr != NULL) {
			//  while there are nodes to copy:
			append(nPtr->myItem); //   append the item in that node
			nPtr = nPtr->myNext; //   advance to next node
		}
		return *this;
	}
}
