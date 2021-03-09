/* To run the BST_Tester class
 * Student: Sebene Yi (ssy3) for CS 112 at Calvin College (proj09)
 * Date: April 30, 2019
 */
#include "BST_Tester.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

int main() {
	BST_Tester bstt;
	bstt.runTests();

	BST<long> bst;

	string file;
	for (unsigned i=0; i < 10; i++) {
		cout << "Please enter a file: " << flush;
		cin >> file;
		unsigned duplicateNum;

		ifstream fin(file.c_str());
		assert(fin.is_open());
		while (!fin.eof()) {
			long insertNum = 0;
			fin >> insertNum;
			if (insertNum == 0) {
				continue;
			}
			try {
				bst.insert(insertNum);
			} catch (Exception& ex) {
				duplicateNum++;
			}
		}
		fin.close();
		cout << "Height is: " << bst.getHeight() << endl;
		cout << "Number of duplicates is: " << duplicateNum << endl;
	}
	cout << "Finished!" << endl;
}

