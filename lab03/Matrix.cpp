/* Matrix.cpp defines Matrix class methods.
 * Student Name: Sebene Yi (ssy3)
 * Date: 03/4/19
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * edited by: Sebene Yi for proj04
 */

#include "Matrix.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//default constructor
Matrix::Matrix() {
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
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	fin >> myRows;
	fin >> myColumns;
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
	Matrix<Item> m3(m2.getRows(), m2.getColumns());
	if ( m2.myRows != myRows) {
		throw invalid_argument("different sized rows.");
	}
	if (m2.myColumns != myColumns){
		throw invalid_argument("different sized columns.");
	}
	for(unsigned i = 0; i <myRows; ++i) {
		for (unsigned j=0; j<myColumns; j++) {
			m3[i][j] = (myVec[i][j] - m2.myVec[i][j]);
	}
	}
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
	Matrix<Item> m2(myColumns, myRows);
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
