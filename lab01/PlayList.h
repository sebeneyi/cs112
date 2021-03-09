/*
 * PlayList.h declares class PlayList.
 *
 *  Created on: Feb 5, 2019
 *  Author: ssy3 at Calvin College for CS 112 lab01
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Song.h"
#include <vector>   // STL vector
#include <string>
using namespace std;

class PlayList {
public:
	PlayList(const string& filename);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(unsigned year) const;
	vector<Song> searchByTitlePhrase(const string& phrase) const;

private:
      vector<Song> mySongs;
};

#endif /* PLAYLIST_H_ */
