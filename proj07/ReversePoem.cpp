/*
 * ReversePoem.cpp defines the methods of the Reverse Poem Class
 * Date: April 1, 2019
 * Student: Sebene Yi for CS 112 at Calvin College (proj07)
 */

#include "ReversePoem.h"
#include "Stack.h"
#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;

/*
 * constructor that takes a string filename
 * @param: string filename
 * precondition: the file must have a reverse poem
 */
ReversePoem::ReversePoem(string filename) {
	ifstream fin(filename.c_str());
	assert ( fin.is_open() );
	getline(fin, myTitle);
	getline(fin, myAuthor);

	Stack<string> Poem(1);
	string currentline;
	getline(fin, currentline);
	while (!fin.eof() ) {
		getline(fin, currentline);
		try {
			Poem.push(currentline);
		} catch (const StackException& se) {
			Poem.setCapacity(Poem.getCapacity() * 2);
			Poem.push(currentline);
			}
		myBody += currentline + '\n';
	}
	unsigned size = Poem.getSize();
	for (unsigned i=0; i<size; ++i) {
		string reverseline = Poem.pop();
		myBodyReversed += reverseline + '\n';
	}
}
