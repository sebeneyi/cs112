/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (proj09)
 * Date: April 30, 2019
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template<class Item>

class BST {
public:
	BST();                        //constructor

	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();

	void insert(const Item& it);
	bool contains(const Item& it) const;

	unsigned getHeight() const;

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();

            void insert(const Item& it);
            bool contains(const Item& it) const;
            unsigned getHeight() const;
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

/* Default constructor
 * initializes private variables of the class BST
 * by: Sebene Yi
 */
template<class Item>
BST<Item>::BST() {
	myNumItems = 0;
	myRoot = NULL;
}

/* Destructor
 * deletes or deallocates memory
 * by: Joel Adams
 */
template<class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

/* explicit node constructor
 * initializes values of a node
 * param: const Item& it
 * by: Joel Adams
 */
template<class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

/* node destructor
 * deletes or dealloactes memory
 * by: Joel Adams
 */
template<class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

/* checks to see if the BST is empty
 * return: bool
 * by: Joel Adams
 */
template<class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

/* gets the number of items
 * return: unsigned myNumItems
 * by: Joel Adams
 */
template<class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

/* method to transervePreorder
 * by: Joel Adams
 */
template<class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

/* node method to tranversePreorder
 * by: Joel Adams
 */
template<class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

/* method to cout an item with a space between
 * by: Joel Adams
 */
template<class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

/* method to tranversePostorder
 * by: Sebene Yi
 */
template<class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

/* method to tranversePostorder through Node
 * by: Joel Adams
 */
template<class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

/* method to tranverseInorder
 * by: Sebene Yi
 */
template<class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

/* method to tranverseInorder through Node
 * by: Sebene Yi
 */
template<class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

/* inserts an item to the BST
 * param: const Item& it
 * postcondition: new item if valid and myNumItems++
 * by: Sebene Yi
 */
template<class Item>
void BST<Item>::insert(const Item& it) {
	if ( isEmpty() ) {
		myRoot = new Node(it);
	}
	else {
		try {
		myRoot->insert(it);
		} catch (Exception& e) {
			throw Exception("BST::insert():", "bad value to insert");
		}
	}
	myNumItems++;
}

/* inserts an item through the node
 * param: const Item& it
 * postcondition: new item if valid
 * by: Sebene Yi
 */
template<class Item>
void BST<Item>::Node::insert(const Item& it){
	if (it < myItem) {
		if (myLeft == NULL) {
			myLeft = new Node(it);
		} else {
			myLeft->insert(it);
		}
	} else if (it > myItem) {
			if (myRight == NULL) {
				myRight = new Node(it);
			} else {
				myRight->insert(it);
			}
		} else if (it == myItem) {
			throw Exception("Node::insert():", "already has this item in the BST!");
	}
}

/* checks to see if BST contain an item
 * param: const Item& it
 * return: bool
 * by: Sebene Yi
 */
template<class Item>
bool BST<Item>::contains(const Item& it) const {
	if ( isEmpty() ) {
		return false;
	}
	else {
		return myRoot->contains(it);
	}
}

/* checks to see if item is in the BST through Node
 * param: const Item& it
 * return: bool
 * by: Sebene Yi
 */
template<class Item>
bool BST<Item>::Node::contains(const Item& it) const {
	if (it < myItem) {
		if (myLeft == NULL) {
			return false;
		} else {
			return myLeft->contains(it);
		}
	} else if (it > myItem) {
		if (myRight == NULL) {
			return false;
		} else {
			return myRight->contains(it);
		}
	} else if (it == myItem) {
		return true;
	}
}

/* returns the height of the BST tree
 * return: unsigned
 * by: Sebene Yi
 */
template<class Item>
unsigned BST<Item>::getHeight() const {
	if ( isEmpty() ) {
		return 0;
	}
	else {
		return myRoot -> getHeight();
	}
}

/* returns the height of the BST Tree through node
 * return: unsigned
 * by: Sebene Yi
 */
template<class Item>
unsigned BST<Item>::Node::getHeight() const {
	if (myLeft == NULL and myRight == NULL) {
		return 1;
	}
	unsigned heightLeft = 0;
	unsigned heightRight = 0;
	if (myLeft != NULL) {
		heightLeft += myLeft->getHeight();
	}
	if (myRight != NULL) {
		heightRight += myRight->getHeight();
	}
	if (heightLeft > heightRight) {
		return heightLeft + 1;
	} else {
		return heightRight + 1;
	}
}
#endif /*BST_H_*/

