/*
 * vecInterface.cpp defines the methods for VecInterface.h
 *
 *  Created on: Feb 21, 2019
 *      Author: Sebene Yi (ssy3) and Rebekah Cross (rjc35)
 */

#include "vecInterface.h"
#include <iostream>
using namespace std;

void vecInterface::runApp() {
	cout << "\n We will create a vector to your specifications." << endl;
	cout << "1- enter the number of dimensions: " << endl;
	unsigned size;
	cin >> size;
	cout << "2- enter a starting position: " << endl;
	Vec v0(size);
	unsigned value;
	for (unsigned i=0; i<size; i++) {
		cout << "value: " << flush;
		cin >> value;
		v0[i] = value;
	}
	cout << "3- enter an arbitrary number of vectors: " << endl;
	unsigned number;
	cin >> number;
	Vec sumV(size);
	sumV = v0;
	for (unsigned i=0; i<number; i++) {
		unsigned value;
		Vec v(size);
		for (unsigned i=0; i<size; i++) {
			cout << "value: " << flush;
			cin >> value;
			v[i] = value;
		}
		if (i != size -1) {
			cout << "New vector values: " << endl;
		}
		sumV = sumV + v;
	}
	cout << "This is the sum: " << flush;
	cout << "{" << flush;
	for (unsigned i=0; i<size; ++i) {
		cout << sumV[i] << flush;
		if (i != size -1) {
			cout << ","  << flush;
		}
	}
	cout << "}" << endl;
	}

