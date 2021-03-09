/*
 * main.cpp tests the classes in this project.
 *
 *  Created on: Feb 10, 2019
 *  Author: ssy3 at Calvin College for CS 112 proj01
 */

#include "SongTester.h"
#include "PlayListTester.h"

int main() {
	SongTester sTester;
	sTester.runTests();

	PlayListTester plTester;
	plTester.runTests();
}

