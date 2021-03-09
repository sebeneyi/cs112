/*
 * PlayList.h declares class PlayList.
 *
 *  Created on: Feb 10, 2019
 *  Author: ssy3 at Calvin College for CS 112 proj01
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

	vector<Song> addSong(const Song& newSong);
	vector<Song> removeSong(const Song& aSong);


private:
      vector<Song> mySongs;
};

#endif /* PLAYLIST_H_ */
