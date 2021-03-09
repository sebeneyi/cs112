 /*
  * main.cpp
  * Date: April 1, 2019
  * Student: Sebene Yi for CS 112 at Calvin College (proj07)
  */

#include "ReversePoem.h"
#include "StackTester.h"
#include <iostream>
using namespace std;

int main() {
	StackTester st;
	st.runTests();
	cout << "\nEnter the name of the poem file: ";
	string poemFile;
	cin >> poemFile;
	ReversePoem reversePoem(poemFile);
	cout << reversePoem.getTitle() << "\n"
		 << reversePoem.getAuthor() << "\n"
		 << "\n*** Top-To-Bottom ***\n\n"
		 << reversePoem.getBody()
		 << "\n\n*** Bottom-To-Top ***\n\n"
		 << reversePoem.getBodyReversed()
		 << endl;
}
