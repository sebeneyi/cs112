/* Palindrome.h declares methods for the class Palindrome.
 * Date: April 16, 2019
 * Student: Sebene Yi (ssy3) for CS112 at Calvin College (proj08)
 */

#ifndef PALINDROME_H_
#define PALINDROME_H_

#include <string>
using namespace std;

class Palindrome {
public:
	Palindrome(string infile, string outfile);

	void detectPalindrome();
	bool isPalindrome(string line);

	string getMyInFile() { return myInFile; }
	string getMyOutFile() { return myOutFile; }

private:
	string myInFile;
	string myOutFile;
};

#endif /* PALINDROME_H_ */
