/*
 * List.h declares methods for List class.
 * Student: Sebene Yi (ssy3) and Rebekah Cross (rjc35)
 * Date: March 11, 2019
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <fstream>
using namespace std;

typedef double Item;
template<class Item>

class List {
public:
	List(); 																// default constructor
	void append(const Item& it);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	~List(); 																//destructor
	List(const List& original); 											//copy constructor
	List& operator=(const List& original);

	bool operator==(const List& original);									//by: Rebekah Cross (member 1)
	void readFrom(ifstream& cin);											//by: Rebekah Cross (member 1)
	void writeTo(string fileName, char sep);								//by: Rebekah Cross (member 1)
	void prepend(const Item& number);										//by: Rebekah Cross (member 1)
	void insert(const Item& num, int index);								//by: Rebekah Cross (member 1)

	bool operator!=(const List& original); 									//by: Sebene Yi (member 2)
	void writeTo(ostream& out, char separator) const;						//by: Sebene Yi (member 2)
	void readFrom(const string filename); 									//by: Sebene Yi (member 2)
	unsigned getIndexOf(Item it) const;										//by: Sebene Yi (member 2)
	Item remove(int index);													//by: Sebene Yi (member 2)

private:
	struct Node {
		Item myItem;
		Node * myNext;
		Node(); 					//default node constructor
		Node(Item it, Node * next); //explicit node constructor
		~Node();
	};

	Node * myFirst;
	Node * myLast;

	unsigned mySize;

	friend class ListTester;
};

/*
 * default constructor initializing default values
 * @param:
 * return:
 */
template<class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

/*
 * Node default constructor initializing default values to nodes
 * @param:
 * return:
 */
template<class Item>
List<Item>::Node::Node() {
		myItem = Item();
		myNext = NULL;
}

/*
 * Node explicit constructor initializing given values to nodes
 * @param:
 * return:
 */
template<class Item>
List<Item>::Node::Node(Item it, Node * next) {
	myItem = it;
	myNext = next;
}

/*
 * adds Item it to the list
 * @param: Item it
 * return: a new list
 */
template<class Item>
void List<Item>::append(const Item& it) {
	List<Item>::Node* n1 = new List<Item>::Node(it, NULL);
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
template<class Item>
unsigned List<Item>::getSize() const {
	return mySize;
}

/*
 * gets the first node in a list
 * @param:
 * return: Item with a node whose address is in myFirst
 */
template<class Item>
Item List<Item>::getFirst() const {
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
template<class Item>
Item List<Item>::getLast() const {
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
template<class Item>
List<Item>::~List() {
   delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
   myFirst = myLast = NULL; // clear myFirst and myLast (optional)
   mySize = 0;              // clear mySize (optional)
}

/*
 * destructor to reclaim dynamic memory
 * @param:
 * return:
 */
template<class Item>
List<Item>::Node::~Node() {
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
template<class Item>
List<Item>::List(const List<Item>& original) {
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
template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
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
 * equality method- returns true if the same list
 * input = list
 * output = bool
 * Author: Rebekah Cross
 */
template < class Item>
bool List<Item>::operator==(const List<Item>& original) {
	//both empty lists
	if ( mySize == 0 and original.getSize() == 0) {
		return true;
	}
	else if ( (mySize == original.mySize) and
			(myFirst == original.myFirst) and
			(myLast == original.myLast) ) {
		for (unsigned i = 0; i < mySize; ++i) {
			if (myFirst->myNext->myItem != original.myFirst->myNext->myItem) {
				//returns false if differing values
				return false;
		}
	}return true;
}
	return false;
}

/*
 * reads values from a file into a list
 * Author: Rebekah Cross
 */
template < class Item>
void List<Item>::readFrom(ifstream& fin) {
	char character;
	unsigned value;
	fin >> std::noskipws;		//ensures whitespace is read
	while ( character != '\n' ) {
		fin >> value >> character ;
		append(value);			//appends value to the list
	}
}

/*
 * writes values from a list into a file
 * uses user designated separator between values
 * Author: Rebekah Cross
 */
template < class Item>
void List<Item>::writeTo(string fileName, char sep) {
	ofstream out( fileName.c_str() );
	Node* ptr;
	ptr = myFirst;
	while ( ptr != NULL ) {
		out << ptr->myItem;
		out << sep;
		ptr = ptr->myNext;	//iterates through pointers
	}
}

/*
 * adds a value to the beginning of a list
 * Author: Rebekah Cross
 */
template < class Item>
void List<Item>::prepend(const Item& number) {
	Node* nodePtr = new Node(number, NULL);
	if ( (mySize == 0) ) {
		myLast = nodePtr;
	}
	else { nodePtr->myNext = myFirst; }
	myFirst = nodePtr;
	mySize = mySize + 1;
}

/*
 * inserts a value into the list at assigned index
 * Author: Rebekah Cross
 */
template < class Item>
void List<Item>::insert(const Item& num, int index) {
	if ( mySize == 0) {
		throw ( invalid_argument(" this is an empty list " ));
	}
	Node* ptr = new Node(num, NULL);
	//keep track of previous and current pointers
	Node* point = myFirst;
	Node* earlierPoint;
	for ( int i = 0; i < index; ++i) {
		//move pointers through the list to assigned index
		earlierPoint = point;
		point = point->myNext;
	}
	earlierPoint->myNext = ptr;
	ptr->myNext = point;

}

/*
 * defining != operator
 * @param: const List&
 * returns: boolean
 * by: Sebene Yi for proj05
 */
template<class Item>
bool List<Item>::operator!=(const List<Item>& original) {
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
template<class Item>
void List<Item>::writeTo(ostream& out, char separator) const {
	Node* nPtr = myFirst;
	unsigned i = 1;
	while (nPtr != NULL) {
		if (i == mySize) {
			out << nPtr ->myItem;
		}
		else {
		out << nPtr->myItem << separator;}
		nPtr = nPtr->myNext; 		//   advance to next node
		i++;
	}
	out << "\n";
}

/*
 * read from string
 * @param: const string filename
 * return:
 * by: Sebene Yi for proj 05
 */
template<class Item>
void List<Item>::readFrom(const string filename) {
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
template<class Item>
unsigned List<Item>::getIndexOf(Item it) const {
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
template<class Item>
Item List<Item>::remove(int index) {
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

#endif /* LIST_H_ */
