/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (lab09)
 * Date: April 23, 2019
 */
 
#include "BST.h"

/* Default constructor
 * initializes private variables of the class BST
 * by: Sebene Yi
 */
BST::BST() {
	myNumItems = 0;
	myRoot = NULL;
}

/* Destructor
 * deletes or deallocates memory
 * by: Joel Adams
 */
BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

/* explicit node constructor
 * initializes values of a node
 * param: const Item& it
 * by: Joel Adams
 */
BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

/* node destructor
 * deletes or dealloactes memory
 * by: Joel Adams
 */
BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

/* checks to see if the BST is empty
 * return: bool
 * by: Joel Adams
 */
bool BST::isEmpty() const {
	return myNumItems == 0;
}

/* gets the number of items
 * return: unsigned myNumItems
 * by: Joel Adams
 */
unsigned BST::getNumItems() const {
	return myNumItems;
}

/* method to transervePreorder
 * by: Joel Adams
 */
void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

/* node method to tranversePreorder
 * by: Joel Adams
 */
void BST::Node::traversePreorder() {
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
void BST::Node::processItem() {
		cout << ' ' << myItem;
}

/* method to tranversePostorder
 * by: Sebene Yi
 */
void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

/* method to tranversePostorder through Node
 * by: Joel Adams
 */
void BST::Node::traversePostorder() {
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
void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

/* method to tranverseInorder through Node
 * by: Sebene Yi
 */
void BST::Node::traverseInorder() {
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
void BST::insert(const Item& it) {
	if ( isEmpty() ) {
		myRoot = new Node(it);
	}
	else {
		try {
		myRoot->Node::insert(it);
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
void BST::Node::insert(const Item& it){
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
bool BST::contains(const Item& it) const {
	if ( isEmpty() ) {
		return false;
	}
	else {
		return myRoot->Node::contains(it);
	}
}

/* checks to see if item is in the BST through Node
 * param: const Item& it
 * return: bool
 * by: Sebene Yi
 */
bool BST::Node::contains(const Item& it) const {
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
