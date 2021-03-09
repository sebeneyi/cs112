/* ListTester.cpp defines the test methods for class List.
 * Student: Sebene Yi (ssy3)
 * Date: March 25, 2019
 * Joel Adams, for CS 112 at Calvin College.
 * edited by: Sebene Yi for CS 112 proj06
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
#include <fstream>
using namespace std;

typedef double Item;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();

	testEquality();
	testReadFromStream();
	testWriteToFile();
	testPrepend();
	testInsert();

	testInequality();
	testWriteToStream();
	testReadFromString();
	testGetIndexOf();
	testRemove();

	testInsertAfter();
	testInsertBefore();
	testOperator();

	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<Item> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}


void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<Item>::Node aNode;
	assert( aNode.myItem == Item() );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<Item>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<Item>::Node *n3 = new List<Item>::Node(33, NULL);
	List<Item>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<Item> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<Item> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<Item> list1;
	List<Item> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<Item> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<Item> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<Item> list1;
	List<Item> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<Item> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<Item> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<Item> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<Item> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<Item> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<Item> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<Item> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<Item> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<Item> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}

//Author: Rebekah Cross
void ListTester::testEquality() {
	cout << "Testing equality... " << flush;

	//compare empty lists
	List<double> listA;
	List<double> listB;
	assert( listA == listB);
	cout << " 0 " << flush;

	//compare the same list
	List<double> list1;
	list1.append(11);
	list1.append(22);
	list1.append(33);
	assert( list1 == list1);
	cout << " 1 " << flush;

	//compare same sized lists
	List<double> list2;
	list2.append(44);
	list2.append(55);
	list2.append(66);
	assert ( !(list1 == list2) );
	cout << " 2 " << flush;

	//compare two different sized lists
	List<double> list3;
	list3.append(44);
	list3.append(55);
	list3.append(66);
	list3.append(77);
	assert ( !(list3 == list2) );
	cout << " 3 " << flush;

	cout << " Passed! " << endl;
}

//Author: Rebekah Cross
void ListTester::testReadFromStream() {
	cout << "Testing readFrom(ifstream)... " << flush;
	ifstream in( "ListTest1.txt");
	assert( in.is_open() );		//open file
	List<double> list0;					//allocate empty list
	list0.readFrom(in);			//read values into list from file
	assert( list0.myFirst != NULL );
	assert( list0.myFirst->myNext->myItem == 2);
	in.close();					//close file

	cout << " Passed!" << endl;
}

//Author: Rebekah Cross
void ListTester::testWriteToFile() {
	cout << "Testing writeTo(file)... " << flush;
	List<Item> list0;			//initial list
	list0.append(11);
	list0.append(22);
	list0.append(33);
	list0.writeTo( "ListTestOutput.txt", '\t');			//write values to file

	List<Item> list1;
	list1.readFrom("ListTestOutput.txt");				//read values from file into list
	assert( list1.myFirst != list0.myFirst );
	assert( list1.myFirst->myItem == 11);
	assert( list1.myLast->myItem == 33);

	cout << " Passed!" << endl;
}

//Author: Rebekah Cross
void ListTester::testPrepend() {
	cout << "-prepend... " << flush;

	//empty case
	List<double> list0;
	list0.prepend(-1);
	assert(list0.myFirst != NULL);
	assert(list0.myFirst->myItem == -1);
	cout << " 0 " << flush;

	//non-empty case
	List<double> list1;
	list1.append(12);
	list1.append(13);
	list1.prepend(11);
	assert(list1.myFirst->myItem == 11);
	assert(list1.myFirst->myNext->myItem == 12);
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

//Author: Rebekah Cross
void ListTester::testInsert() {
	cout << "-insert... " << flush;
	//empty case which should throw an error
	try {
		List<double> list0;
		list0.insert(1,3);
		cerr << "inserting into an empty set";
		exit(1);
	}
	catch( invalid_argument& ) {
		cout << " 0 " << flush;
	}

	//non empty case
	List<double> list1;
	list1.append(11);
	list1.append(33);
	list1.append(44);
	list1.insert(22, 1);
	assert( list1.myFirst->myNext->myItem == 22);
	cout << " 1 " << flush;

	cout << " Passed!" << endl;
}

/*
 * testing inequality
 * by: Sebene Yi for proj05
 */
void ListTester::testInequality() {
	cout << "Testing !=... " << flush;
	// empty to empty
	List<Item> list1;
	List<Item> list2;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// same size to different values
	List<Item> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);

	List<Item> list4;
	list4.append(22);
	list4.append(44);
	list4.append(55);

	assert (list3 != list4);
	cout << " 2 " << flush;

	// different size
	List<Item> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);

	List<Item> list6;
	list6.append(11);
	list6.append(22);

	assert (list5 != list6);
	cout << " 3 " << flush;

	// same first number, but different rest of the values
	List<Item> list7;
	list7.append(44);
	list7.append(55);
	list7.append(66);

	List<Item> list8;
	list8.append(44);
	list8.append(22);
	list8.append(33);

	assert (list7 != list8);

	cout << " 4 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

/*
 * testing write to stream
 * by: Sebene Yi for proj05
 */
void ListTester::testWriteToStream() {
	cout << "Testing writeTo(stream)... " << flush;
	List<Item> aList;
	aList.append(1);
	aList.append(2);
	aList.append(3);

	ofstream fout("ListStreamOut.txt");
	assert (fout.is_open());
	aList.writeTo(fout, '\t');
	fout.close();

	ifstream fin("ListStreamOut.txt");
	List<Item> bList;
	bList.readFrom(fin);
	assert (fin.is_open());

	assert(aList.getSize()== 3);
	assert(aList.myFirst != NULL);
	assert(aList.myLast != NULL);
	assert(aList.getFirst() == 1);
	assert(aList.getLast() == 3);

	cout << "Passed!" << endl;
}

/*
 * testing read from string
 * by: Sebene Yi for proj05
 */
void ListTester::testReadFromString() {
	cout << "Testing readFrom()... " << flush;

	List<Item> rList1;
	rList1.readFrom("ListTest1.txt");
	assert( rList1.myFirst->myItem == 1);
	assert( rList1.myFirst->myNext->myItem == 2);
	assert( rList1.myFirst->myNext->myNext->myItem == 3);
	cout << " 1 " << flush;

	List<Item> rList2;
	rList2.readFrom("ListTest2.txt");
	assert( rList2.myFirst->myItem == 4);
	assert( rList2.myFirst->myNext->myItem == 5);
	assert( rList2.myFirst->myNext->myNext->myItem == 6);
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

/*
 * testing getting the index of a value
 * by: Sebene Yi for proj05
 */
void ListTester::testGetIndexOf() {
	cout << "Testing getIndexOf()... " << flush;

	List<Item> list1;
	list1.append(11);
	list1.append(22);
	list1.append(33);

	assert( list1.getIndexOf(11) == 0);
	assert( list1.getIndexOf(22) == 1);
	assert( list1.getIndexOf(33) == 2);
	cout<< " 1 " << flush;

	List<Item> list2;
	list2.append(1);
	list2.append(2);
	list2.append(3);

	assert( list2.getIndexOf(1) == 0);
	assert( list2.getIndexOf(2) == 1);
	assert( list2.getIndexOf(3) == 2);
	cout<< " 2 " << flush;

	List<Item> list3;
	list3.append(44);
	list3.append(55);
	list3.append(66);

	assert( list3.getIndexOf(44) == 0);
	assert( list3.getIndexOf(55) == 1);
	assert( list3.getIndexOf(66) == 2);
	assert( list3.getIndexOf(77) == -1);
	cout<< " 3 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testRemove() {
	cout << "Testing Remove()... " << flush;
	//empty list
	List<Item> aList;
	try {
		aList.remove(0);
		cerr << "List is empty!";
		exit(1);
	}
	catch (
		invalid_argument&
	){
	cout<< " 0 " << flush;}

	// removing with negative index
	List<Item> list1;
	list1.append(22);
	assert( list1.remove(-1) == 22);
	assert( list1.mySize == 0);
	cout << " 1 " << flush;

	//removing with positive index
	List<Item> list2;
	list2.append(33);
	assert( list2.remove(0) == 33);
	assert( list2.mySize==0);
	cout << " 2 " << flush;

	// removing middle value
	List<Item> list3;
	list3.append(44);
	list3.append(55);
	list3.append(66);
	assert( list3.remove(1) == 55);
	assert( list3.mySize == 2);
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

//testing insertAfter function
void ListTester::testInsertAfter() {
	cout << "Testing insertAfter()... " << flush;

	List<string> aList;

	//empty list
	try {
		aList.insertAfter("Ann", "Bob");
		cerr << "insertAfter worked on an empty list";
		exit(1);
	}
	catch(range_error& re) {
		cout << " 0 " << flush;
	}

	//test with one person without the person existing
	aList.append("Doug");

	assert(not aList.insertAfter("Howie", "Trebek"));
	assert(aList.mySize == 1);
	assert(aList.getFirst() == "Doug");
	assert(aList.myFirst == aList.myLast);

	cout << " 1 " << flush;

	//test with one person with the person existing
	aList.insertAfter("Doug", "Howie");

	assert(aList.myFirst != aList.myLast);
	assert(aList.getFirst() == "Doug");
	assert(aList.getLast() == "Howie");

	cout << " 2 " << flush;

	//the person you want to insert before is at the end
	aList.insertAfter("Howie", "Trebek");

	assert(aList.mySize == 3);
	assert(aList.getFirst() == "Doug");
	assert(aList.getLast() == "Trebek");

	cout << " 3 " << flush;

	//the person you want to insert before is at the beginning
	aList.insertBefore("Doug", "Roger");

	assert(aList.mySize == 4);
	assert(aList.getFirst() != "Doug");
	assert(aList.getLast() != "Roger");

	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}

//testing insertBefore function
void ListTester::testInsertBefore() {
	cout << "Testing insertBefore()... " << flush;

	List<string> bList;

	//empty list
	try {
		bList.insertBefore("Ann", "Bob");
		cerr << "insertBefore worked on an empty list";
		exit(1);
	}
	catch(range_error& re) {
		cout << " 0 " << flush;
	}

	//test with one person without the person existing
	bList.append("Doug");

	assert(not bList.insertBefore("Howie", "Trebek"));
	assert(bList.mySize == 1);
	assert(bList.getFirst() == "Doug");
	assert(bList.myFirst == bList.myLast);
	cout << " 1 " << flush;

	//test with one person with the person existing
	bList.insertBefore("Doug", "Howie");

	assert(bList.myFirst != bList.myLast);
	assert(bList.getFirst() == "Howie");
	assert(bList.getLast() == "Doug");
	cout << " 2 " << flush;

	//the person you want to insert before is at the end
	bList.insertBefore("Doug", "Trebek");

	assert(bList.mySize == 3);
	assert(bList.getFirst() == "Howie");
	assert(bList.getLast() == "Doug");
	cout << " 3 " << flush;

	//the person you want to insert before is at the beginning
	bList.insertBefore("Howie", "Roger");

	assert(bList.mySize == 4);
	assert(bList.getFirst() == "Roger");
	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}

//testing extraction operator <<
void ListTester::testOperator() {
	cout << "Testing operator<<()... " << flush;

	List<string> l1;
	l1.append("Dallas");
	l1.append("Austin");
	l1.append("Baylor");

	//writing to file
	ofstream fout("operatorTest.txt");
	fout << l1;
	fout.close();

	//reading from file
	ifstream fin("operatorTest.txt");
	string s1;
	fin >> s1;
	fin.close();

	assert(s1 == "Dallas=Austin=Baylor");
	cout << " 1 " << flush;

	List<string> l2;
	l2.append("Dallas");
	l2.append("Austin");
	l2.append("Baylor");
	l2.append("Worth");
	l2.prepend("Fort");

	//writing to file
	ofstream fout2("operatorTest2.txt");
	fout2 << l2;
	fout2.close();

	//reading from file
	ifstream fin2("operatorTest2.txt");
	string s2;
	fin2 >> s2;
	fin2.close();

	assert(s2 == "Fort=Dallas=Austin=Baylor=Worth");
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}
