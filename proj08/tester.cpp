/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (proj08)
 * Date: April 16, 2019
 */

#include "ArrayQueueTester.h"
#include "StackTester.h"
#include "PalindromeTester.h"
 
 int main() {
 	ArrayQueueTester aqt;
 	aqt.runTests();
 	StackTester st;
 	st.runTests();
 	PalindromeTester pt;
 	pt.runTests();
 }
