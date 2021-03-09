/* MatrixTester.h declares test-methods for class Matrix.
 * Student: Sebene Yi(ssy3) and Samuel Zeleke (sgz4)
 * Date: 4 Mar, 2019
 * Proj04: Matrix operations
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */
 
#ifndef MATRIXTESTER_H_
#define MATRIXTESTER_H_

#include "Matrix.h"

typedef double Item;

class MatrixTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testExplicitConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testSubscripts();
	void testReadSubscript(const Matrix<Item>& mat);
	void testTranspose();
	void testAddition();
	void testSubtraction();
	void testMultiply();
	void testReadFromStream();
	void testReadFromFile();
	void testWriteToStream();
	void testWriteToFile();
};

#endif /*MATRIXTESTER_H_*/
