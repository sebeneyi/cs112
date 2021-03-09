/*
 * List.cpp defines List class methods.
 *  Created on: Mar 08, 2019
 *  Author: Sebene Yi (ssy3) at Calvin College for CS 112 proj05
 */

#include "List.h"
#include <stdexcept>
#include <cassert>
#include <fstream>
using namespace std;

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

/*
 * defining != operator
 * @param: const List&
 * returns: boolean
 * by: Sebene Yi for proj05
 */

bool List::operator!=(const List& original) {
	if (this != &original) {
		return true;}
	if (mySize != original.mySize) {
		return true;
	}

	Node* nPtr = myFirst;
	Node* oPtr = original.myFirst;
	for (unsigned i = 0; i < mySize; i++) {
			if (nPtr -> myItem != oPtr -> myItem) {
				return true;
			}
			nPtr = nPtr -> myNext;
			oPtr = oPtr -> myNext;
		}
	return false;
}

/*
 * write to stream
 * @param: ostream, char separator const
 * return:
 * by: Sebene Yi for proj 05
 */

void List::writeTo(ostream& out, char separator) const {
	Node* nPtr = myFirst;
	while (nPtr != NULL) {
		out << nPtr->myItem << separator;
		nPtr = nPtr->myNext; 		//   advance to next node
	}

}

/*
 * read from string
 * @param: const string filename
 * return:
 * by: Sebene Yi for proj 05
 */

void List::readFrom(const string filename) {
	ifstream fin( filename.c_str() );
	assert( fin.is_open());
	int size;

	while (!fin.eof()) {
		fin >> size;
		this->append(size);
	}
	fin.close();
}

/*
 * get index of value
 * @param: const Item&
 * return: unsigned index of value
 * by: Sebene Yi for proj 05
 */
unsigned List::getIndexOf(Item it) const {
	Node* nPtr = myFirst;
	for (unsigned i = 0; i<mySize; i++) {
		if (nPtr->myItem == it) {
			return i;
		}
		else {if (nPtr->myItem != it){
			nPtr = nPtr->myNext;
		}
		}
	}
	return -1;
}

/*
 * removing by index
 * @param: int index
 * return: item
 * by: Sebene Yi for proj 05
 */
Item List::remove(int index) {
	Item remove;
	Node* nPtr = myFirst;

	if (mySize == 0) {
		throw invalid_argument("The list is empty!");
	}
	if (index<=0) {
		myFirst = myFirst->myNext;
		mySize --;
	}
	if (index >= mySize) {
		remove = myLast->myItem;
		delete myLast;
	}
	else {
		for (unsigned i=1; i<mySize; ++i) {
			nPtr = nPtr -> myNext;
			if (i==index) {
				remove = nPtr->myItem;
				mySize --;
		}
	}
	}
	return remove;
	delete nPtr;
}
