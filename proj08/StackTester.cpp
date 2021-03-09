/* StackTester.cpp defines test-methods for the 
 *  dynamically allocated (array) Stack operations
 * Joel Adams, for CS 112 at Calvin College
 * Date: April 16, 2019
 * Student: Sebene Yi for CS 112 at Calvin College (proj08)
 */

#include "StackTester.h"
#include "Stack.h"
#include <iostream>  // cout, cerr, ...
#include <cassert>   // assert()
#include <cstdlib>   // exit()
using namespace std;

typedef int Item;

void StackTester::runTests() {
	cout << "Testing class Stack..." << endl;
	testConstructor();
	testIsEmpty();
	testPushPeekTopAndIsFull();
	testPop();
	testCopyConstructor();
	testAssignment();
	testDestructor();
	testGetSizeAndGetAndSetCapacity();
	cout << "All tests passed!\n" << endl;
}

void StackTester::testConstructor() {
	cout << "- testing constructor... " << flush;
	// invalid parameter
	try {
		Stack<Item> s1(0);
		cerr << "\nConstructed stack of size 0\n";
		exit(1);
	} catch (const StackException& se) {
		cout << se << flush;
		cout << " 0 " << flush;
	}
	// valid parameter
	Stack<Item> s2(3);
	cout << " 1 " << flush;
	cout << " Passed!" << endl;
}

void StackTester::testIsEmpty() {
	cout << "- testing isEmpty()... " << flush;
	// capacity 1
	Stack<Item> s1(1);
	assert( s1.isEmpty() );
	cout << " 1 " << flush;
	// capacity > 1
	Stack<Item> s2(3);
	assert( s2.isEmpty() );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}


void StackTester::testPushPeekTopAndIsFull() {
	cout << "- testing push()... " << flush;
	// test with capacity 1
	Stack<Item> s1(1);
	s1.push(11);
	assert( s1.peekTop() == 11 );
	assert( !s1.isEmpty() );
	assert( s1.isFull() );
	try {
		s1.push(22);
		cerr << "\npush() worked on a full stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 1 " << flush;
	}
	// test with capacity > 1
	Stack<Item> s2(3);
	s2.push(11);
	assert( s2.peekTop() == 11 );
	s2.push(22);
	assert( s2.peekTop() == 22 );
	s2.push(33);
	assert( s2.peekTop() == 33 );
	try {
		s2.push(44);
		cerr << "\npush() worked on a full stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 2 " << flush;
	}
	cout << " Passed! " << endl;
}

void StackTester::testPop() {
	cout << "- testing pop()... " << flush;
	// try empty, capacity 1
	Stack<Item> s1(1);
	assert( s1.isEmpty() );
    try {
            s1.peekTop();
            cerr << "\npeekTop() worked on empty stack (size 1)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 0a " << flush;
    }
	try {
		s1.pop();
		cerr << "\npop() worked on empty stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 0b " << flush;
	}

	// try empty, capacity > 1
	Stack<Item> s2(3);
	try {
		s2.pop();
		cerr << "\npop() worked on empty stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 1a " << flush;
	}
    try {
            s2.peekTop();
            cerr << "\npeekTop() worked on empty stack (size 3)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 1b " << flush;
    }

	// try non-empty, capacity 1
	Stack<Item> s3(1);
	s3.push(11);
	assert( s3.peekTop() == 11 );
	assert( s3.pop() == 11 );
	cout << " 2 " << flush;
	try {
		s3.pop();
		cerr << "\ns3.pop() worked on empty stack (size 1)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 2a " << flush;
	}
    try {
            s3.peekTop();
            cerr << "\ns3.peekTop() worked on empty stack (size 1)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 2b " << flush;
    }

	// try non-empty, capacity > 1
	Stack<Item> s4(3);
	s4.push(11);
	s4.push(22);
	s4.push(33);
	assert( s4.peekTop() == 33 );
	assert( s4.pop() == 33 );
	assert( s4.peekTop() == 22 );
	assert( s4.pop() == 22 );
	assert( s4.peekTop() == 11 );
	assert( s4.pop() == 11 );
	cout << " 3 " << flush;
	try {
		s4.pop();
		cerr << "\ns4.pop() worked on empty stack (size 3)\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 3a " << flush;
	}
    try {
            s4.peekTop();
            cerr << "\ns4.peekTop() worked on empty stack (size 3)\n";
            exit(1);
    } catch (const StackException& se) {
            cout << " 3b " << flush;
    }

	cout << " Passed!" << endl;
}

void StackTester::testCopyConstructor() {
	cout << "- testing copy constructor... " << flush;
	// minimal empty Stack
	Stack<Item> s1(1);
	Stack<Item> s2(s1);
	assert( s2.isEmpty() );
	assert( s2.myArray != NULL );
	assert( s2.myCapacity == 1 );
	assert( s2.myArray != s1.myArray );
	cout << " 1 " << flush;
	// minimal non-empty Stack
	Stack<Item> s3(1);
	s3.push(11);
	Stack<Item> s4(s3);
	assert( !s4.isEmpty() );
	assert( s4.isFull() );
	assert( s4.peekTop() == 11 );
	assert( s4.myArray != s3.myArray );
	cout << " 2 " << flush;
	// non-minimal, non-empty stack
	Stack<Item> s5(3);
	s5.push(11);
	s5.push(22);
	s5.push(33);
	Stack<Item> s6(s5);
	assert( s6.myCapacity == s5.myCapacity );
	assert( s6.mySize == s5.mySize );
	assert( s6.myArray != s5.myArray );
	assert( s6.pop() == 33 );
	assert( s6.pop() == 22 );
	assert( s6.pop() == 11 );
	assert( s5.peekTop() == 33 );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void StackTester::testAssignment() {
	cout << "- testing assignment... " << flush;
	// minimal empty Stacks, same size
	Stack<Item> s1(1);
	Stack<Item> s2(1);
	s2 = s1;
	assert( s2.isEmpty() );
	assert( s2.myArray != NULL );
	assert( s2.myArray != s1.myArray );
	assert( s2.myCapacity == 1 );
	cout << " 1 " << flush;
	// minimal non-empty Stack to empty Stack, same capacity
	Stack<Item> s3(1);
	s3.push(11);
	Stack<Item> s4(1);
	s4 = s3;
	assert( !s4.isEmpty() );
	assert( s4.isFull() );
	assert( s4.peekTop() == 11 );
	assert( s4.myArray != s3.myArray );
	cout << " 2 " << flush;
	// minimal empty stack to non-empty stack, same capacity
	Stack<Item> s5(1);
	Stack<Item> s6(1);
	s6.push(11);
	s6 = s5;
	assert( s6.isEmpty() );
	assert( s6.myArray != NULL );
	assert( s6.myArray != s5.myArray );
	assert( s6.myCapacity == 1 );
	cout << " 3 " << flush;
	// non-minimal non-empty stack to empty stack, different capacities
	Stack<Item> s7(3);
	s7.push(11);
	s7.push(22);
	s7.push(33);
	Stack<Item> s8(2);
	s8 = s7;
	assert( s8.myArray != s7.myArray );
	assert( s8.myCapacity == s7.myCapacity );
	assert( s8.mySize == s7.mySize );
	assert( s8.pop() == 33 );
	assert( s8.pop() == 22 );
	assert( s8.pop() == 11 );
	assert( s7.peekTop() == 33 );
	cout << " 4 " << flush;
	// non-minimal, empty stack to non-empty stack, different capacities
	Stack<Item> s9(2);
	Stack<Item> s10(3);
	s10.push(11);
	s10.push(22);
	s10.push(33);
	s10 = s9;
	assert( s10.isEmpty() );
	assert( s10.myArray != s9.myArray );
	assert( s10.myCapacity == s10.myCapacity );
	cout << " 5 " << flush;
	// self-assignment, minimal size
	Stack<Item> s11(1);
	s11.push(11);
	s11 = s11;
	assert( s11.isFull() );
	assert( !s11.isEmpty() );
	cout << " 6 " << flush;
	// chaining
	Stack<Item> s12(2);
	s12.push(11);
	s12.push(22);
	Stack<Item> s13(1);
	Stack<Item> s14(1);
	s14 = s13 = s12;
	assert( s14.isFull() );
	assert( s14.myArray != s13.myArray );
	assert( s14.myArray != s12.myArray );
	assert( s14.pop() == 22 );
	assert( s14.pop() == 11 );
	assert( s14.isEmpty() );
	cout << " 7 " << flush;
      // self-assignment, non-minimal size
      s13 = s13;
	assert( !s13.isEmpty() );
	assert( s13.isFull() );
	assert( s13.pop() == 22 );
	assert( s13.pop() == 11 );
	assert( s13.isEmpty() );
	cout << " 8 " << flush;
	cout << "Passed!" << endl;
}

void StackTester::testDestructor() {
	cout << "- testing destructor..." << flush;
	// minimal, empty
	Stack<Item> s1(1);
	s1.~Stack();
	assert( s1.isEmpty() );
	assert( s1.myArray == NULL );
	assert( s1.myCapacity == 0 );
	cout << " 1 " << flush;
	// minimal, non-empty
	Stack<Item> s2(1);
	s2.push(11);
	s2.~Stack();
	assert( s2.isEmpty() );
	assert( s2.myArray == NULL );
	assert( s2.myCapacity == 0 );
	cout << " 2 " << flush;
	// non-minimal, empty
	Stack<Item> s3(3);
	s3.~Stack();
	assert( s3.isEmpty() );
	assert( s3.myArray == NULL );
	assert( s3.myCapacity == 0 );
	cout << " 3 " << flush;
	// non-minimal, non-empty
	Stack<Item> s4(3);
	s4.push(11);
	s4.push(22);
	s4.push(33);
	s4.~Stack();
	assert( s4.isEmpty() );
	assert( s4.myArray == NULL );
	assert( s4.myCapacity == 0 );
	cout << " 4 " << flush;
	cout << " Passed!" << endl;
}

void StackTester::testGetSizeAndGetAndSetCapacity() {
	cout << "- testing getSize(), getCapacity(), and setCapacity()..." << flush;
	//testing getCapacity on invalid parameter
	try {
		Stack<Item> s0(0);
		s0.getCapacity();
		cerr << "\nConstructed stack of size 0\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 0a " << flush;
	}

	//testing setCapacity on invalid parameter
	try {
		Stack<Item> s1(3);
		s1.setCapacity(0);
		cerr << "\nConstructed stack of size 0\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 0b " << flush;
	}

	//testing capacity on capacity < getSize
	Stack<Item> s3(5);
	s3.push(1);
	s3.push(2);
	try {
		s3.setCapacity(1);
		cerr << "\nConstructed stack of size 0\n";
		exit(1);
	} catch (const StackException& se) {
		cout << " 1 " << flush;
	}

	//minimal case
	Stack<Item> s2(1);
	assert (s2.getSize() == 0);
	assert (s2.getCapacity() == 1);
	cout << " 2 " << flush;


	//non empty case
	Stack<Item> s4(5);
	assert ( s4.getSize() == 0);
	assert ( s4.getCapacity() == 5);
	cout << " 3a " << flush;

	//testing size
	s4.push(3);
	assert ( s4.getSize() == 1 );
	assert ( s4.getCapacity() == 5);
	cout << " 3b " << flush;

	//testing size and set capacity
	s4.push(4);
	s4.push(5);
	s4.push(6);
	s4.setCapacity(7);
	assert( s4.getSize() == 4 );
	assert( s4.getCapacity() == 7);
	cout << " 4a " << flush;

	//testing size and set capacity 2
	s4.pop();
	s4.pop();
	s4.setCapacity(3);
	assert( s4.getSize() == 2);
	assert( s4.getCapacity() == 3);
	cout << " 4b " << flush;

	cout << " Passed!" << endl;

}

