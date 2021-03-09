/* array.cpp defines "C style" array operations
 * Name: Sebene Yi
 * Date: 02/12/19
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "array.h"

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
