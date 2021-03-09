/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Sebene Yi (ssy3)
 * Date: 02/26/19
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * edited by: Sebene Yi for lab04
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {
public:
	Matrix(); //default constructor
	unsigned getRows() const;
	unsigned getColumns() const;
	Matrix(unsigned rows, unsigned columns); // explicit constructor
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item> & operator[](unsigned const index);
	bool operator==(const Matrix& m2) const;

private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

#endif
