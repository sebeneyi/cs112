/* ArrayQueueTester.h declares the class that tests class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (proj08)
 * Date: April 16, 2019
 */
 
#ifndef QUEUETESTER_H_
#define QUEUETESTER_H_

#include "ArrayQueue.h"

class ArrayQueueTester {
public:
	void runTests();
	void testConstructor();
	void testAppend();
	void testRemove();
	void testCopyConstructor();
	void testAssignment();
	void testSetCapacity();
};

#endif /*QUEUETESTER_H_*/
