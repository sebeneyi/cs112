/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Sebene Yi
 * Date: 02/19/19
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"
#include <stdexcept>
#include <ostream>
#include <istream>
using namespace std;

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

Vec::Vec(unsigned size) {
	mySize = size;
	if ( mySize > 0 ) {
		myArray = new Item[mySize];
		for ( unsigned i = 0; i < mySize; i++) {
			myArray[i] = {0};
		}
	}
	else { myArray = NULL;}
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if ( original.mySize > 0) {
		myArray = new Item[mySize];
		for (unsigned i=0; i<mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
	else { myArray = NULL;}
}

Vec& Vec::operator=(const Vec& original) {
	if (&original != this) {
		if (mySize != original.mySize) {
			if (mySize >0) {
				delete [] myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		for (unsigned i=0; i<mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}


	return *this;
}

unsigned Vec::getSize() const {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize or mySize == 0) {
		throw range_error("Array not in range!");
	}
	else {
	myArray[index] = it;}
}

Item Vec::getItem(unsigned index) const {
	if (index >= mySize or mySize == 0) {
			throw range_error("Array not in range!");
		}
		else {
		return myArray[index];}
}

void Vec::setSize(unsigned newSize) {
if (mySize != newSize) {
	if (newSize == 0) {
		delete [] myArray;
		myArray = NULL;
		mySize = 0;
	}
	else {
		Item * newArray = new Item[newSize];
		if (mySize < newSize) {
			for (unsigned i=0; i<mySize; i++) {
				newArray[i] = myArray[i];
			}
			for (unsigned i=mySize; i < newSize; i++){
				newArray[i] = 0;
			}
		}
		else {
			for(unsigned i= 0; i<newSize; i++) {
				newArray[i] = myArray[i];
			}
		}
		mySize = newSize;
		delete [] myArray;
		myArray = newArray;
		}
	}
}

bool Vec::operator==(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return false;}

	else {for (unsigned i = 0; i<mySize; i++) {
			if (myArray[i] != v2.myArray[i])  {
				return false;
			}
		}
	return true;
}
}

void Vec::writeTo(ostream& out) const {
	for (unsigned i =0; i<mySize; i++) {
		out << myArray[i] << '\t';
	}
}

void Vec::readFrom(istream& in) {
	for (unsigned i=0; i<mySize; i++){
		in >> myArray[i];
	}
}


Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}
