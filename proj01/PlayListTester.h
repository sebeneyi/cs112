/*
 * PlayListTester.h tests the PlayList class.
 *
 *  Created on: Feb 10, 2019
 *  Author: ssy3 at Calvin College for CS 112 proj01
 */

#ifndef PLAYLISTTESTER_H_
#define PLAYLISTTESTER_H_
#include <string>
using namespace std;

class PlayListTester {
public:
	void runTests();
	void testConstructors();
	void testSearchByArtist();
	void testSearchByYear();
	void testSearchByTitlePhrase();
	void testAddSongAndRemoveSong();
//	save() const;
};

#endif /* PLAYLISTTESTER_H_ */
