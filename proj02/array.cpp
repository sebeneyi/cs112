/* array.cpp defines "C style" array operations
 * Name: Sebene Yi
 * Date: 02/18/19
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "array.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <cassert>
using namespace std;


void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}

void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}

double average(double *a, unsigned size) {
	double sum = 0.0;
	double avg;
	for (unsigned i = 0; i < size; i++) {
		sum += *a;
		a++;
	}
	avg = sum / size;
	return avg;
}

double sum(double *a, unsigned size) {
	double sum = 0.0;
	for (unsigned i=0; i < size; i++) {
		sum += *a;
		a++;
	}
	return sum;
}

void read(istream& in, double *a, unsigned size) {
	for (unsigned i=0; i<size; i++) {
		in >> a[i];
	}
}

void fill(const string& fileName, double *&a, unsigned &numValues) {
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	fin >> numValues;
	double *values = new double[numValues];
	for (unsigned i=0; i<numValues; i++) {
		fin >> values[i];
	}
	delete [] a;
	a = values;
	fin.close();
}

void resize(double *&a, unsigned oldSize, unsigned newSize) {
	double * newArray = new double[newSize];
	if (newSize != oldSize) {
		if (newSize > oldSize) {
			for (unsigned i=0; i<oldSize; i++){
				newArray[i] = a[i];}
			for (unsigned i=newSize; i < oldSize; i++){
				newArray[i] = 0;
				}
		}
		if (oldSize > newSize) {
			for (unsigned i=0; i<newSize; i++) {
				newArray[i] = a[i];
				}
			}
}
	delete [] a;
	a = newArray;
}

void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3) {
	size3 = size1 + size2;
	delete [] a3;
	double * newArray = new double[size3];
	for (int i=0; i<size1; i++) {
		newArray[i] = a1[i];
	}
	for (int i=0; i<size2; i++){
		newArray[i + size1] = a2[i];
	}
 a3 = newArray;
}
