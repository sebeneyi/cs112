/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student: Sebene Yi(ssy3) and Samuel Zeleke (sgz4)
 * Date: 4 Mar, 2019
 * Proj04: Matrix operations
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */
#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

template<class Item>

class Matrix {
public:
	Matrix(); //default constructor
	unsigned getRows() const;
	unsigned getColumns() const;
	Matrix(unsigned rows, unsigned columns); // explicit constructor
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item> & operator[](unsigned const index);
	bool operator==(const Matrix<Item>& m2) const;

	//By Team Member 1: Samuel Zeleke
	bool operator!=(const Matrix<Item>& m2) const;
	void readFrom(istream& in);
	void writeTo(const string& fileName);
	Matrix<Item> operator+(const Matrix<Item>& m2) const;

	//By Team Memeber 2: Sebene Yi
	void writeTo(ostream& out) const;
	void readFrom(const string& fileName);
	Matrix<Item> operator-(const Matrix<Item>& m2);
	Matrix<Item> getTranspose() const;

private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	friend class MatrixTester;
};

/*
 * constructor sets the parameters to default value of 0
 * @param:
 * return:
 */
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

/*
 * returns the amount of rows in matrix
 * @precondition: a matrix
 * return: myRows
 */
template<class Item>
unsigned Matrix<Item>::getRows() const {
	return myRows;
}

/*
 * return amount of columns in Matrix
 * @precondition: a matrix
 * return: myColumns
 */
template<class Item>
unsigned Matrix<Item>::getColumns() const {
	return myColumns;
}

/*
 * explicit constructor sets the parameters explicitly
 * @param: unsigned rows, unsigned columns
 * return:
 */
template<class Item>
Matrix<Item>::Matrix (unsigned rows, unsigned columns) {
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
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const {
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
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index) {
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
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
    if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
         return false;
    } else {
         return myVec == m2.myVec;
    }
}

/*
 * write values of m to cout for proj04
 * @param: ostream
 * return: void
 * by: Sebene Yi (ssy3)
 */
template<class Item>
void Matrix<Item>::writeTo(ostream& out) const {

	//goes through the entire matrix to extract the value to ostream
	for (unsigned i =0; i<myRows; i++) {
		for (unsigned j = 0; j<myColumns; j++){
			out << myVec[i][j] << '\t';
		} out << '\n';
	}
}

/*
 * fill m with values stored in a file name for proj04
 * @param: a file name
 * return: void
 * by: Sebene Yi (ssy3)
 */
template<class Item>
void Matrix<Item>::readFrom(const string& fileName) {

	//Create filestream
	ifstream fin(fileName.c_str());
	assert(fin.is_open());

	//Update row and column numbers
	fin >> myRows;
	fin >> myColumns;

	//Create matrix and update the values to the values in file
	Matrix m2 = Matrix(myRows, myColumns);
	for (unsigned i=0; i<myRows; i++) {
		for (unsigned j=0; j<myColumns; j++){
			fin >> m2[i][j];
		}
	}

	myVec = m2.myVec;
	fin.close();
}

/*
 * defining subtraction method for proj04
 * @param: Matrix m2
 * return: Matrix
 * by: Sebene Yi (ssy3)
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator-(const Matrix<Item>& m2) {

	//define difference containing item
	Matrix<Item> m3(m2.getRows(), m2.getColumns());

	//Check if the matrix sizes are the same; if not throw a error
	if ( m2.myRows != myRows) {
		throw invalid_argument("different sized rows.");
	}
	if (m2.myColumns != myColumns){
		throw invalid_argument("different sized columns.");
	}

	//Update the value of the entries of the container matrix to hold the differences
	for(unsigned i = 0; i <myRows; ++i) {
		for (unsigned j=0; j<myColumns; j++) {
			m3[i][j] = (myVec[i][j] - m2.myVec[i][j]);
	}
	}
	//return difference
	return m3;
}

/*
 * changes columns into rows and rows into columns for proj04
 * @param:
 * return: Matrix
 * by: Sebene Yi (ssy3)
 */
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() const {

	//create transpose matrix
	Matrix<Item> m2(myColumns, myRows);

	//change the values of the matrix to be the transpose of the current matrix
	for (unsigned i=0; i<myColumns; i++) {
		for (unsigned j=0; j<myRows; j++){
			m2.myVec[i][j] = myVec[j][i];
		}
	}
	return m2;
}

/*
 * Inequality operator overload
 * @param:const Matrix& m2
 * Description: Define inequality for Matrix object.
 * Written by: Samuel Zeleke
 * Post-condition:
 *
 */
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& m2) const{

	//REturn true of the sizes are different
	if ( myRows != m2.myRows || myColumns != m2.myColumns ){
		return true;
	}

	//if sizes are the same and they are "non-zero" check every entry
	if ( myRows != 0 && m2.myRows != 0){

		//Use the operator overload defined in Vec to check every column
		for (unsigned i = 0; i < myRows; i++){
			if (myVec[i] != m2.myVec[i]){
				return true;
			}
		}
	}
	return false;
}

/*
 * readFrom
 * @param:const istream& in
 * Description: Define inequality for Matrix object.
 * Written by: Samuel Zeleke
 * Post-condition: the matrix's values modified to values entered from stream
 *
 */
template<class Item>
void Matrix<Item>::readFrom(istream& in){

	//use insertion operator to modify every entry of matrix
	for(unsigned rowNumber = 0; rowNumber < myRows; rowNumber++){

		for(unsigned columnNumber = 0; columnNumber < myColumns; columnNumber++){
			in >> myVec[rowNumber][columnNumber];
		}
	}
}


/*
 * writeTo
 * @param:const string& fileName
 * Description: writes the entries of Matrix fileName.txt
 * Written by: Samuel Zeleke
 * Post-condition: fileName.txt created/modified
 *
 */
template<class Item>
void Matrix<Item>::writeTo(const string& fileName){

	//open filestream
	ofstream fout(fileName.c_str());

	//Change the
	fout << myRows << "\t" << myColumns << "\n";
	writeTo(fout);
}


/*
 * Addition operator overload
 * @param:const const Matrix&
 * Description: Define addition for Matrix object.
 * Written by: Samuel Zeleke
 * Post-condition: the matrix's values modified to values entered from stream
 *
 */
template<class Item>
Matrix<Item> Matrix<Item>::operator+(const Matrix<Item>& m2) const{

	//Check if the matrixes are empty. if so, return empty matrix
	if (myRows == 0 && m2.myRows == 0){
		Matrix<Item> emptyMatrix;
		return emptyMatrix;
	}

	//throw error if their sizes are not equal
	if ( myRows != m2.myRows || myColumns != m2.myColumns ){
		throw invalid_argument("Invalid operand size: the sizes of the operands are different.");
	}

	//Create temp Matrix and change its entries to the sum of the operands
	Matrix<Item> temp(myRows, myColumns);

	for (unsigned row = 0; row < temp.myRows; row++){

		for (unsigned column = 0; column < temp.myColumns; column++){
			temp[row][column] = myVec[row][column] + m2[row][column];
		}
	}

	return temp;
}

#endif
