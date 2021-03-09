/*
 * PlayList.cpp defines in the PlayList methods.
 *
 *  Created on: Feb 10, 2019
 *  Author: ssy3 at Calvin College for CS 112 proj01
 */

#include "PlayList.h"
#include <fstream>      // ifstream
#include <cassert>      // assert()
#include <vector>
using namespace std;

/* PlayList constructor
* @param: fileName, a string
* Precondition: fileName contains the name of a playlist file.
*/
PlayList::PlayList(const string& fileName) {
    // open a stream to the playlist file
    ifstream fin( fileName.c_str() );
    assert( fin.is_open() );

    // read each song and append it to mySongs
    Song s;
    string separator;
    while (true) {
        s.readFrom(fin);
        if ( !fin ) { break; }
        getline(fin, separator);
        mySongs.push_back(s);
    }

    // close the stream
    fin.close();
}

/* Retrieve length of the playlist
* Return: the number of songs in the playlist.
*/
unsigned PlayList::getNumSongs() const {
	   /* Retrieve length of the playlist
	    * Return: the number of songs in the playlist.
	    */
	   return mySongs.size();
}

/* Search by artist
 * @param: artist, a string.
 * Return: a vector containing all the Songs in mySongs by artist.
 */
vector<Song> PlayList::searchByArtist(const string& artist) const {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); i++) {
      if ( mySongs[i].getArtist().find(artist) != string::npos ) {
         v.push_back( mySongs[i] );
      }
   }

   return v;
}

/* Search by year
 * @param: year, unsigned.
 * Return: a vector containing all the Songs in mySongs by year.
 */
vector<Song> PlayList::searchByYear(unsigned year) const {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); i++) {
      if ( mySongs[i].getYear() == year ) {
         v.push_back( mySongs[i] );
      }
   }

   return v;
}

/* Search by title phrase
 * @param: phrase, a string.
 * Return: a vector containing all the Songs in mySongs by title phrase.
 */
vector<Song> PlayList::searchByTitlePhrase(const string& phrase) const {
   vector<Song> v;

   for (unsigned i = 0; i < mySongs.size(); i++) {
      if ( mySongs[i].getTitle().find(phrase)!= string::npos ) {
         v.push_back( mySongs[i] );
      }
   }

   return v;
}

/* Add a song
 * @param: song.
 * Return: a vector containing all the Songs including a new song.
 */
vector<Song> PlayList::addSong(const Song& newSong) {
	vector<Song> v;

	mySongs.push_back(newSong);

	return v;
}

/* Remove a song
 * @param: song.
 * Return: a vector containing all the Songs removing a song.
 */
vector<Song> PlayList::removeSong(const Song& aSong) {
	vector<Song> v;

	mySongs.pop_back(aSong);

	return v;
}
