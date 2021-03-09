/* PalindromeTester.cpp defines the methods for the tests for class Palindrome
 * Date: April 16, 2019
 * Student: Sebene Yi (ssy3) for CS112 at Calvin College (proj08)
 */

#include "PalindromeTester.h"
#include "Palindrome.h"
#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

void PalindromeTester::runTests() {
	cout << "Testing class Palindrome..." << endl;
	testConstructor();
	testDetectPalindrome();
	testIsPalindrome();
	cout << "All Tests Passed!" << endl;
}
void PalindromeTester::testConstructor() {
	cout << "- testing constructor..." << flush;

	Palindrome p1("testInFile.txt", "testOutFile.txt");
	assert( p1.getMyInFile() == "testInFile.txt");
	assert( p1.getMyOutFile() == "testOutFile.txt");
	cout << " 0 " << flush;

	cout << " Passed!" << endl;
}

void PalindromeTester::testDetectPalindrome() {
	cout << "- testing detectPalindrome()..." << flush;

	//empty case
	Palindrome p0("emptyIn.txt", "emptyOut.txt");
	p0.detectPalindrome();
	string empty;
	ifstream fin("emptyOut.txt");
	getline(fin, empty);
	assert(empty=="");
	getline(fin, empty);
	assert(empty=="");
	assert(fin.eof());
	fin.close();
	cout << " 0 " << flush;

	//non empty casestestOutFile
	Palindrome p1("testInFile.txt", "testOutFile.txt");
	p1.detectPalindrome();
	string line;
	ifstream fin1("testOutFile.txt");
	getline(fin1, line);
	assert(line == "Kayak ***");
	getline(fin1, line);
	assert(line == "Don't nod. ***");
	getline(fin1, line);
	assert(line == "");
	getline(fin1, line);
	assert(line == "a mess of a line");
	getline(fin1, line);
	assert(line == "taco! cat! ***");
	getline(fin1, line);
	assert(line == "");
	getline(fin1, line);
	assert(line == "this.is.not.real.");
	fin1.close();
	cout << " 1 " << flush;

	//final test
	Palindrome pTest("drawnOnward.txt", "finalTestOutput.txt");
	pTest.detectPalindrome();
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}

void PalindromeTester::testIsPalindrome() {
	cout << "- testing isPalindrome()..." << flush;

	Palindrome p1("inFile.txt", "outFile.txt");
	// check it handles empty line
	assert( ! p1.isPalindrome("") );
	cout << " 0 " << flush;

	// checks one word palindrome
	assert( p1.isPalindrome("Kayak") );
	cout << " 1 " << flush;

	// checks that it ignores punctuation
	assert( p1.isPalindrome("Don't nod") );
	cout << " 2 " << flush;

	// checks capitalization
	assert( p1.isPalindrome("My gym") );
	cout << " 3 " << flush;

	//checks capitalization and punctuation
	assert( p1.isPalindrome("Step on no pets!") );
	cout << " 4 " << flush;

	cout << " Passed!" << endl;
}
