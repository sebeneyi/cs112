/*
 * Song.h declares a class for storing song information.
 *
 *  Created on: Feb 5, 2019
 *  Author: ssy3 at Calvin College for CS 112 lab01
 */

#ifndef SONG_H_
#define SONG_H_

#include <string>
using namespace std;

class Song {
public:
	Song();
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;

	Song(const string& title, const string& artist, unsigned year);

	void readFrom(istream& in);

	void writeTo(ostream& out) const;

//    bool operator==(const Song& song2) const;

private:
	string myTitle;
	string myArtist;
	unsigned myYear;

};

#endif /* SONG_H_ */
