/* ListTester.h declares the test-class for class List.
 * Student: Sebene Yi (ssy3)
 * Date: March 05, 2019
 * Joel Adams, for CS 112 at Calvin College.
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
};

#endif /*LISTTESTER_H_*/
