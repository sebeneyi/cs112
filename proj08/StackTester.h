/* StackTester.h declares a test-class for a dynamically allocated (array) Stack.
 * Joel Adams, for CS 112 at Calvin College
 * Date: April 16, 2019
 * Student: Sebene Yi for CS 112 at Calvin College (proj08)
 */

#ifndef STACKTESTER_H_
#define STACKTESTER_H_


class StackTester {
public:
	void runTests();
	void testConstructor();
	void testIsEmpty();
	void testPushPeekTopAndIsFull();
	void testPop();
	void testCopyConstructor();
	void testAssignment();
	void testDestructor();

	void testGetSizeAndGetAndSetCapacity();
};

#endif /*STACKTESTER_H_*/

