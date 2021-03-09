/*
 * PlayListTester.cpp defines the PlayList test-methods.
 *
 *  Created on: Feb 10, 2019
 *  Author: ssy3 at Calvin College for CS 112 proj01
 */

#include "PlayListTester.h"
#include "PlayList.h"
#include <cassert>
#include <iostream>
using namespace std;

void PlayListTester::runTests() {
	cout << "\nTesting Class Playlist..." << endl;
	testConstructors();
	testSearchByArtist();
	testSearchByYear();
	testSearchByTitlePhrase();
	testAddSongAndRemoveSong();
	cout << "All tests passed!" << endl;
}

void PlayListTester::testConstructors() {
	cout<< "- constructors..." << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );
	cout << " 0 " << flush;

	cout << " Passed! " << endl;
}

void PlayListTester::testSearchByArtist() {
   cout << "- searchByArtist()... " << flush;
   // load a playlist with test songs
   PlayList pList("testSongs.txt");

   // empty case (0)
   vector<Song> searchResult = pList.searchByArtist("Cream");
   assert( searchResult.size() == 0 );
   cout << " 0 " << flush;

   // case of 1
   searchResult = pList.searchByArtist("Baez");
   assert( searchResult.size() == 1 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   cout << " 1 " << flush;

   // case of 2
   searchResult = pList.searchByArtist("Beatles");
   assert( searchResult.size() == 2 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   assert( searchResult[1].getTitle() == "Penny Lane" );
   cout << " 2 " << flush;

   cout << " Passed!" << endl;
}

void PlayListTester::testSearchByYear() {
	 cout << "- searchByYear()..." << flush;
	 PlayList pList("testSongs.txt");

	 vector<Song> searchResult = pList.searchByYear(2015);
	 assert ( searchResult.size() == 0 );
	 cout << " 0 " << flush;

	 searchResult = pList.searchByYear(2012);
	 assert ( searchResult.size()==1 );
	 assert ( searchResult[0].getTitle() == "Call Me Maybe") ;
	 cout << " 1 " << flush;

	 searchResult = pList.searchByYear(1967);
	 assert ( searchResult.size() == 2);
	 assert ( searchResult[0].getTitle() == "Let It Be" );
	 assert ( searchResult[1].getTitle() == "Penny Lane" );
	 cout << " 2 " << flush;

	 cout << " Passed! " << endl;

}

void PlayListTester::testSearchByTitlePhrase() {
	 cout << "- searchByTitlePhrase()..." << flush;
	 PlayList pList("testSongs.txt");

	 vector<Song> searchResult = pList.searchByTitlePhrase("Boy");
	 assert ( searchResult.size() == 0);
	 cout << " 0 " << flush;

	 searchResult = pList.searchByTitlePhrase("Call");
	 assert ( searchResult.size() == 1 );
	 assert ( searchResult[0].getTitle() == "Call Me Maybe" );
	 cout << " 1 " << flush;

	 searchResult = pList.searchByTitlePhrase("Be");
	 assert ( searchResult.size() == 2);
	 assert ( searchResult[0].getTitle() == "Let It Be" );
	 assert ( searchResult[1].getTitle() == "Let It Be" );
	 cout << " 2 " << flush;

	 cout << " Passed! " << endl;
}

void PlayListTester::testAddSongAndRemoveSong() {
	  cout << "- addSong()..." << flush;
	  PlayList pList("testSongs.txt");

	  vector<Song> searchResult = pList.addSong("George");
	  assert ( searchResult.getNum() == 5);
	  cout << " 0 " << flush;

	  searchResult = pList.removeSong("George");
	  assert ( searchResult.getNum() == 4);
	  cout << " 1 " << flush;

	  cout << " Passed! " << endl;
}

//PlayList::removeSong(const Song& aSong) {
//
//}
//
//PlayList::save() const {
//
//}
