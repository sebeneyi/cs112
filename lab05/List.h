/*
 * List.h declares methods for List class.
 *  Created on: Mar 5, 2019
 *  Author: Sebene Yi (ssy3) at Calvin College for CS 112 lab05
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using namespace std;

typedef double Item;

class List {
public:
	List(); 					// default constructor
	void append(const Item& it);
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	~List(); 					// destructor
	List(const List& original); //copy constructor
	List& operator=(const List& original);

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

#endif /* LIST_H_ */
