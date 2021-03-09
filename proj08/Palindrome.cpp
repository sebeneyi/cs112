/* Palindrome.cpp defines the methods of class Palindrome
 * Date: April 16, 2019
 * Student: Sebene Yi (ssy3) for CS112 at Calvin College (proj08)
 */

#include "Palindrome.h"
#include "Stack.h"
#include "ArrayQueue.h"
#include <cassert>
#include <fstream>

/* constructor
 * @param: string infile, string outfile
 */
Palindrome::Palindrome(string infile, string outfile) {
	myInFile = infile;
	myOutFile = outfile;
}

/* detects if the lines in a file are a palindrome
 * @param: none
 * return: void
 * postcondition:
 */
void Palindrome::detectPalindrome() {
	//open streams
	ifstream fin(myInFile.c_str());
	ofstream fout(myOutFile.c_str());
	// test to see if open
	assert( fin.is_open() );
	assert( fout.is_open() );
	// to keep track of the line
	string line;
	// loop to go through the files
	while ( !fin.eof() ) {
		getline(fin, line);
		fout << line;
		if (isPalindrome(line)) {
			fout << " ***";
		}
		fout << '\n';
	}
	// close the streams
	fin.close();
	fout.close();
}

/* returns a bool dependent on whether a given line is a palindrome
 * @param: string line
 * return: bool
 * postcondition:
 */
bool Palindrome::isPalindrome(string line) {
	// check if blank line
	if (line.size() == 0) {
		return false;
	}
	Stack<char> charStack(1);
	ArrayQueue<char> charArrayQueue(1);
	// go through each character
	for (unsigned i=0; i<line.size(); ++i){
		char currentChar = line[i];
		//convert to lowercase
		if (isalpha(currentChar)) {
			currentChar = tolower(currentChar);
			// push lower case character onto a stack
			try {
				charStack.push(currentChar);
			} catch (StackException& se) {
				charStack.setCapacity(charStack.getCapacity() * 2);
				charStack.push(currentChar);
			}
			// add to ArrayQueue
			try {
				charArrayQueue.append(currentChar);
			} catch (FullQueueException& qe) {
				charArrayQueue.setCapacity(charArrayQueue.getCapacity() * 2);
				charArrayQueue.append(currentChar);
			}
		}

	}
	// now empty the stack and (array) queue
	while (!charStack.isEmpty()) {
		char ch1 = charStack.pop();
		char ch2 = charArrayQueue.remove();
		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}


