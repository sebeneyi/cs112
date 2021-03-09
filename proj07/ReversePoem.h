/*
 * ReversePoem.h declares the methods of Reverse Poem Class
 * Date: April 1, 2019
 * Student: Sebene Yi for CS 112 at Calvin College (proj07)
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include <string>
using namespace std;

class ReversePoem {
public:
	ReversePoem(string filename);
	string getTitle() {return myTitle; }
	string getAuthor() {return myAuthor; }
	string getBody() {return myBody; }
	string getBodyReversed() {return myBodyReversed; }

private:
	string myTitle;
	string myAuthor;
	string myBody;
	string myBodyReversed;
};

#endif /* REVERSEPOEM_H_ */
