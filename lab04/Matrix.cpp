/* Matrix.cpp defines Matrix class methods.
 * Student Name: Sebene Yi (ssy3)
 * Date: 02/26/19
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * edited by: Sebene Yi for lab04
 */

#include "Matrix.h"

//default constructor
Matrix::Matrix() {
	myRows = myColumns = 0;
}

/*
 * returns the amount of rows in matrix
 * @precondition: a matrix
 * return: myRows
 */
unsigned Matrix::getRows() const {
	return myRows;
}

/*
 * return amount of columns in Matrix
 * @precondition: a matrix
 * return: myColumns
 */
unsigned Matrix::getColumns() const {
	return myColumns;
}

//explicit constructor
Matrix::Matrix (unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i=0; i< rows; i++) {
		myVec[i].setSize(columns);
	}
}

/*
 * reads what's in [] operator according to index
 * @param: unsigned index
 * return: vector at the index
 */
const Vec<Item>& Matrix::operator[](unsigned index) const {
	if (myRows == 0) {
			throw range_error("it is an empty array.");
		}
		if (index > myRows-1) {
			throw range_error("index exceeds array size.");
		}
		return myVec[index];
	}

/*
 * write in [] operator according to index
 * @param: unsigned index
 * return: vector at the index
 */
Vec<Item>& Matrix::operator[](unsigned index) {
	if (index >= myRows or myRows == 0 ) {
		throw range_error("Bad index value!");
	}
	else {
		return myVec[index];
	}
}

/*
 * compares two matrixes to see if there are the same
 * @param: const Matrix& m2
 * return: boolean
 */
bool Matrix::operator==(const Matrix& m2) const {
    if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
         return false;
    } else {
         return myVec == m2.myVec;
    }
}

