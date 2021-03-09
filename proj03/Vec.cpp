/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Sebene Yi and Rebekah Cross
 * Date: 02/21/19
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 * Edited by: (member 1) Sebene Yi and (member 2) Rebekah Cross
 */

#include "Vec.h"
#include <stdexcept>
#include <ostream>
#include <istream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;

/*
 * sets default value to vec parameters
 */
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

/*
 * sets explicit values to vec parameters
 */
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

/*
 * copies vecs
 */
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

/*
 * destroys my array and sets to default
 */
Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

/*
 * redefines = operator
 * param: const Vec&
 * return: Vec&
 * postcondition:
 */
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

/*
 * returns size of vec
 * param:
 * return: unsigned
 * postcondition:
 */
unsigned Vec::getSize() const {
	return mySize;
}

/*
 * sets an Item in a array
 * param: unsigned, const Item&
 * return:
 * postcondition:
 */
void Vec::setItem(unsigned index, const Item& it) {
	if (index >= mySize or mySize == 0) {
		throw range_error("Array not in range!");
	}
	else {
	myArray[index] = it;}
}

/*
 * retrieves an item by index
 * param: unsigned index
 * return: Item
 * postcondition:
 */
Item Vec::getItem(unsigned index) const {
	if (index >= mySize or mySize == 0) {
			throw range_error("Array not in range!");
		}
		else {
		return myArray[index];}
}

/*
 * sets the size of an array
 * @param: unsigned newSize
 * return:
 * postcondition:
 */
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

/*
 * defines == operator and returns bool
 * return: bool
 * @param: const Vec&
 * postcondition:
 */
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

/*
 * writes to ostream
 * return:
 * @param: ostream&
 * postcondition:
 */
void Vec::writeTo(ostream& out) const {
	for (unsigned i =0; i<mySize; i++) {
		out << myArray[i] << '\t';
	}
}

/*
 * reads from istream
 * return:
 * @param: istream&
 * postcondition:
 */
void Vec::readFrom(istream& in) {
	for (unsigned i=0; i<mySize; i++){
		in >> myArray[i];
	}
}

/*
 * change index i in vec for proj03
 * @param: index
 * by Sebene Yi (ssy3)
 */
Item & Vec::operator[](unsigned const index){
	if (index >= mySize or mySize == 0 ) {
		throw range_error("Bad index value!");
	}
	else {
		return myArray[index];
	}
}

/*
 * inequality for proj03
 * @param: Vec& v2
 * by Sebene Yi (ssy3)
 */
bool Vec::operator!=(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return true;}

	else {for (unsigned i = 0; i<mySize; i++) {
			if (myArray[i] != v2.myArray[i])  {
				return true;
			}
		}
	return false;
	}
}

/*
 * read from for proj03
 * @param: file
 * by Sebene Yi (ssy3)
 */
void Vec::readFrom(const string& fileName) {
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	string sizeLine;
	getline(fin, sizeLine);
	int num = atoi( sizeLine.c_str());
	mySize = num;
	Item *v2 = new Item[mySize];
	for (int i=0; i<num; i++) {
		string line;
		getline(fin, line);
		v2[i] = atoi( line.c_str());
	}
	delete [] myArray;
	myArray = v2;
	fin.close();
}

/*
 * + operator for proj03
 * @param: Vec& v2
 * by Sebene Yi (ssy3)
 */
Vec Vec::operator+(const Vec& v2) {
	Vec v3(mySize);
	if (mySize != v2.mySize) {
		throw invalid_argument("Sizes are different! \n Cannot add!");
	}
	for (unsigned i=0; i<mySize; i++){
		v3[i] = myArray[i] + v2.myArray[i];}
	return v3;
}

/*
 * write to method for Proj3
 * @param: string
 * By: Rebekah Cross
 */
void Vec::writeTo(const string& filename) {
	ofstream out( filename.c_str() );
	out << mySize << endl;
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
	out.close();
}

/*
 * retrieval subscript operator for Proj3
 * @param: unsigned index
 * return: Item value
 * By: Rebekah Cross
 */
Item& Vec::operator[](unsigned index) const {
	if (mySize == 0) {
		throw range_error("it is an empty array.");
	}
	if (index > mySize-1) {
		throw range_error("index exceeds array size.");
	}
	return myArray[index];
}

/*
 * subtraction method for Proj3
 * @param: Vec
 * return: Vec
 * By: Rebekah Cross
 */
Vec Vec::operator-(const Vec& v3) {
	Vec v4(v3.mySize);
	if ( v3.mySize != mySize) {
		throw invalid_argument("different size arrays.");
	}
	for (unsigned i = 0; i <mySize; ++i) {
		v4[i] = (myArray[i] - v3.myArray[i]);
	}
	return v4;
}

/*
 * dot product method for Proj3
 * @param: Vec
 * return: double dot product
 * By: Rebekah Cross
 */
double Vec::operator*(const Vec& v3) {
	double product;
	if ( v3.mySize != mySize) {
		throw invalid_argument("different size arrays.");
	}
	if ( mySize == 0) {
		return 0;
	}
	for (unsigned i = 0; i <mySize; ++i) {
		product = product + (myArray[i] * v3.myArray[i]);
	}
	return product;
}

