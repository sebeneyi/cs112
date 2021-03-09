/* Vec.h provides a simple vector class named Vec.
 * Student Name: Sebene Yi and Rebekah Cross
 * Date: 02/21/19
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 * Edited by: Sebene Yi and Rebekah Cross
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec(); // default constructor
	virtual ~Vec(); // destructor
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

	Item & operator[](unsigned const index);
	bool operator!=(const Vec& v2) const;
	void readFrom(const string& fileName);
	Vec operator+(const Vec& v2);

	Item& operator[](unsigned index) const;
	Vec operator-(const Vec& v3);
	double operator*(const Vec& v3);
	void writeTo(const string& Filename);

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
