/* tester.cpp drives the testing of our Vec template and Matrix class.
 * Student: Sebene Yi(ssy3) and Samuel Zeleke (sgz4)
 * Date: 4 Mar, 2019
 * Proj04: Matrix operations
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

//#include "VecTester.h"
#include "MatrixTester.h"

#include "Application.h"

int main() {
//	VecTester vt;
//	vt.runTests();
	MatrixTester mt;
	mt.runTests();

	Application app;
	app.launch();
}
