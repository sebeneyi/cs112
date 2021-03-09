/* ListTester.h declares the test-class for class List.
 * Student: Sebene Yi (ssy3) and Rebekah Cross (rjc35)
 * Date: March 11, 2019
 * Joel Adams, for CS 112 at Calvin College.
 * edited by: Sebene Yi and Rebekah Cross for CS 112 proj05
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

	void testEquality();		//Rebekah Cross
	void testReadFromStream();	//Rebekah Cross
	void testWriteToFile();		//Rebekah Cross
	void testPrepend();			//Rebekah Cross
	void testInsert();			//Rebekah Cross

	void testInequality(); 				//by: Sebene Yi (member 2)
	void testWriteToStream();			//by: Sebene Yi (member 2)
	void testReadFromString(); 			//by: Sebene Yi (member 2)
	void testGetIndexOf();				//by: Sebene Yi (member 2)
	void testRemove();					//by: Sebene Yi (memeber 2)
};

#endif /*LISTTESTER_H_*/
