/*
 * PlayListTester.h tests the PlayList class.
 *
 *  Created on: Feb 5, 2019
 *  Author: ssy3 at Calvin College for CS 112 lab 01
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
	void testSearchByYear(unsigned year);
	void testSearchByTitlePhrase(const string& phrase);
//	addSong(const Song& newSong);
//	removeSong(const Song& aSong);
//	save() const;
};

#endif /* PLAYLISTTESTER_H_ */
