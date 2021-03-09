/* LinkedQueueTester.h declares the methods of the LinkedQueueTester class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (lab08)
 * Date: April 03, 2019
*/

#ifndef LINKEDQUEUETESTER_H_
#define LINKEDQUEUETESTER_H_

#include "LinkedQueue.h"

class LinkedQueueTester {
public:
	void runTests();
	void testConstructor();
	void testAppend();
	void testRemove();
	void testCopyConstructor();
	void testAssignment();
};

#endif /*LINKEDQUEUETESTER_H_*/
