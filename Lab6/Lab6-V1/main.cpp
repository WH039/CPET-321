/******************************************************/
/*** Title: main.cpp                                ***/
/*** Course: Computational Problem Solving CPET-II  ***/
/*** Developer: Weicheng Haung                      ***/
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
	
	string song_name;
	string song_artist;
	string song_URL;

	int song_select;

	list <Song> song_playlist;
	Song song_l;

	string filename = "my_playlist.txt";
	ifstream playlistFile(filename);

	if (!playlistFile) {
		cout << "Failed to Locate/Open File" << endl;
		cout << "Closing Program" << endl;
		exit(0);
	}

	while (!playlistFile.eof()) {
		getline(playlistFile, song_name);
		getline(playlistFile, song_artist);
		getline(playlistFile, song_URL);
		Song tempSong(song_name, song_artist, song_URL);
		song_playlist.push_back(tempSong);
	}

	playlistFile.close();

	cout << "Song Menu :";
	int i = 0;
	for (auto it = song_playlist.begin(); it != song_playlist.end(); it++) {
		cout << "\n   ( " << i << " ) : ";
		i++;
		it->DisplaySongInfo();

	}

	cout << "\n   ( -1 ) : QUIT" << endl;
	cout << "Select =>";
	cin >> song_select;

	while (song_select != -1) {
		
		if (song_select >= song_playlist.size()) {
			cout << "Sorry, Not A Song Option" << endl;
			system("pause");
		}
		else {
			
			i = 0;
			for (auto it : song_playlist) {
				if (song_select == i) {
					song_l = it;
					cout << "Playing : ";
					song_l.DisplaySongInfo();
					song_l.PlaySong();
					break;
				}
				else {
					i++;
				}
			}
			
		}
		system("cls");
		cout << "Song Menu :";
		int i = 0;
		for (auto it = song_playlist.begin(); it != song_playlist.end(); it++) {
			cout << "\n   ( " << i << " ) : ";
			i++;
			it->DisplaySongInfo();

		}

		cout << "\n   ( -1 ) : QUIT" << endl;
		cout << "Select =>";
		cin >> song_select;
	}

	if (song_select == -1) // Exit Condition
	{
		cout << "Bye Thanks For Playing" << endl;
		exit(0);
	}

}