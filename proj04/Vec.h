/* Vec.h provides a simple vector class named Vec.
 * Student Name: Sebene Yi (ssy3)
 * Date: 03/4/19
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 * Edited by: Sebene Yi for proj 04
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
#include <ostream>
#include <istream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;

template<class Item>

class Vec {
public:
	Vec();
	virtual ~Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	Item& operator[](unsigned index) const;
	Item & operator[](unsigned const index);
	bool operator!=(const Vec& v2) const;
	Vec operator+(const Vec& v2);
	Vec operator-(const Vec& v3);
	double operator*(const Vec& v3);
	void readFrom(const string& fileName);
	void writeTo(const string& Filename);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

//default constructor
template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

//explicit constructor
template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	if ( mySize > 0 ) {
		myArray = new Item[mySize];
		for ( unsigned i = 0; i < mySize; i++) {
			myArray[i] = {0};
		}
	}
	else { myArray = NULL;}
}

//copy constructor
template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	mySize = original.mySize;
	if ( original.mySize > 0) {
		myArray = new Item[mySize];
		for (unsigned i=0; i<mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
	else { myArray = NULL;}
}

// destructor
template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
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

//returns size of vector
template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

//changes item at specific index
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index >= mySize or mySize == 0) {
		throw range_error("Array not in range!");
	}
	else {
	myArray[index] = it;}

}//equality operator
template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
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


//retrieves value
template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (index >= mySize or mySize == 0) {
			throw range_error("Array not in range!");
		}
		else {
		return myArray[index];}
}

//sets vector size
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
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

//write values to a file
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned i =0; i<mySize; i++) {
		out << myArray[i] << '\t';
	}
}

//reads in values from a file
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned i=0; i<mySize; i++){
		in >> myArray[i];
	}
}
/*
 * change index i in vec for proj03
 * @param: index
 * by Sebene Yi (ssy3)
 * edited by: Sebene Yi (ssy3) for lab 04
 */
template<class Item>
Item & Vec<Item>::operator[](unsigned const index){
	if (index >= mySize or mySize == 0 ) {
		throw range_error("Bad index value!");
	}
	else {
		return myArray[index];
	}
}

/*
 * retrieval subscript operator for Proj3
 * @param: unsigned index
 * return: Item value
 * By: Rebekah Cross
 * edited by: Sebene Yi (ssy3) for lab 04
 */
template<class Item>
Item& Vec<Item>::operator[](unsigned index) const {
	if (mySize == 0) {
		throw range_error("it is an empty array.");
	}
	if (index > mySize-1) {
		throw range_error("index exceeds array size.");
	}
	return myArray[index];
}

/*
 * inequality for proj03
 * @param: Vec& v2
 * by Sebene Yi (ssy3)
 * edited by: Sebene Yi (ssy3) for lab 04
 */
template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) const {
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
 * + operator for proj03
 * @param: Vec& v2
 * by Sebene Yi (ssy3)
 * edited by: Sebene Yi (ssy3) for lab 04
 */
template <class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) {
	Vec v3(mySize);
	if (mySize != v2.mySize) {
		throw invalid_argument("Sizes are different! \n Cannot add!");
	}
	for (unsigned i=0; i<mySize; i++){
		v3[i] = myArray[i] + v2.myArray[i];}
	return v3;
}

/*
 * subtraction method for Proj3
 * @param: Vec
 * return: Vec
 * By: Rebekah Cross
 * edited by: Sebene Yi (ssy3) for lab 04
 */
template <class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v3) {
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
 * edited by: Sebene Yi (ssy3) for lab 04
 */
template<class Item>
double Vec<Item>::operator*(const Vec<Item>& v3) {
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

/*
 * read from for proj03
 * @param: file
 * by Sebene Yi (ssy3)
 * edited by: Sebene Yi for lab 04
 */
template<class Item>
void Vec<Item>::readFrom(const string& fileName) {
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
 * write to method for Proj3
 * @param: string
 * By: Rebekah Cross
 * edited by: Sebene Yi (ssy3) for lab 04
 */
template<class Item>
void Vec<Item>::writeTo(const string& filename) {
	ofstream out( filename.c_str() );
	out << mySize << endl;
	for (unsigned i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
	out.close();
}

#endif /*VEC_H_*/
