/*
 * SongTester.h declares a test-class for class Song
 *
 *  Created on: Feb 5, 2019
 *  Author: ssy3 at Calvin College for CS 112 lab01
 */

#ifndef SONGTESTER_H_
#define SONGTESTER_H_

#include "Song.h"

class SongTester {
public:
	void runTests();
	void testConstructors();
	void testReadFrom();
	void testWriteTo();
};

#endif /* SONGTESTER_H_ */
