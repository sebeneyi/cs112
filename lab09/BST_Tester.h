/* BST_Tester.h declares a class to test class BST.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (lab09)
 * Date: April 23, 2019
 */

#ifndef BST_TESTER_H_
#define BST_TESTER_H_

#include "BST.h"
#include <iostream>
#include <cassert>
using namespace std;

class BST_Tester
{
public:
	void runTests();
	void testConstructor();
	void testInsert();
	void testContains();
	void testTraverse();
	void testGetHeight();
};

#endif /*BST_TESTER_H_*/
