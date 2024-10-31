/******************************************************/
/*** Title: main.cpp                                ***/
/*** Course: Computational Problem Solving CPET-II  ***/
/*** Developer: Weicheng Huang                      ***/
/*** Description:                                   ***/
/******************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Song.h"

using namespace std;
using namespace SONG;

int main() {
	// variables
	string song_name;
	string song_artist;
	string song_URL;

	int song_select;

	list <Song> song_playlist;
	Song song_l;

	string filename = "my_playlist.txt";
	ifstream playlistFile(filename);

	// checks for if the file actually opened
	if (!playlistFile) {
		cout << "File was not found" << endl;
		exit(0);
	}

	// inputs song info as wwhile the file is not finished
	while (!playlistFile.eof()) {
		playlistFile >> ws;
		getline(playlistFile, song_name);
		getline(playlistFile, song_artist);
		getline(playlistFile, song_URL);
		Song tempSong(song_name, song_artist, song_URL);
		song_playlist.push_back(tempSong);
	}

	playlistFile.close(); // close file since it is no long in use

	// inital landing screen of program
	cout << "Song Menu :";
	int i = 0; // used to increment the iterator
	for (auto it = song_playlist.begin(); it != song_playlist.end(); it++) {
		cout << "\n   ( " << i << " ) : ";
		i++;
		it->DisplaySongInfo();
	}

	cout << "\n   ( -1 ) : QUIT" << endl;
	cout << "Select => ";
	cin >> song_select;

	while (song_select != -1) {
		// error if the song selected is not possible i.e. greater than the number of songs in list
		if (song_select >= song_playlist.size()) {
			cout << "Sorry, Not A Song Option" << endl;
			system("pause");
		}
		// plays song
		else {
			i = 0;
			for (auto it : song_playlist) {
				if (song_select == i) { // using the iterator and i to match the index of the song to the selection
					song_l = it;
					cout << "Playing : ";
					song_l.DisplaySongInfo();
					song_l.PlaySong();
					break;
				}
				else {
					i++; // increments i if it does not match song_select
				}
				
			}
			
		}

		system("cls");
		// sends user back to landing screen to chose another song.
		cout << "Song Menu :";
		int i = 0;
		for (auto it = song_playlist.begin(); it != song_playlist.end(); it++) {
			cout << "\n   ( " << i << " ) : ";
			i++;
			it->DisplaySongInfo();
		}

		cout << "\n   ( -1 ) : QUIT" << endl;
		cout << "Select => ";
		cin >> song_select;
	}

	if (song_select == -1) // Exit Condition
	{
		cout << "Bye Thanks For Playing" << endl;
		exit(0);
	}

}