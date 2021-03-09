/* ListTester.h declares the test-class for class List.
 * Student: Sebene Yi (ssy3)
 * Date: March 25, 2019
 * Joel Adams, for CS 112 at Calvin College.
 * edited by: Sebene Yi for CS 112 proj06
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();

	void testEquality();
	void testReadFromStream();
	void testWriteToFile();
	void testPrepend();
	void testInsert();

	void testInequality();
	void testWriteToStream();
	void testReadFromString();
	void testGetIndexOf();
	void testRemove();

	void testInsertAfter();
	void testInsertBefore();
	void testOperator();
};

#endif /*LISTTESTER_H_*/
