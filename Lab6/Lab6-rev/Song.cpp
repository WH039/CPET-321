/******************************************************/
/*** Title: Song.cpp                                ***/
/*** Course: Computational Problem Solving CPET-II  ***/
/*** Developer: Weicheng Huang                      ***/
/*** Description: cpp file for class Song           ***/
/******************************************************/

#include "Song.h"

using namespace SONG;

Song::Song() { //default constructor, does nothing
	
}

Song::Song(string s_name, string s_artist, string s_URL) { // sets the name, artist and url of a song
	name   = s_name;
	artist = s_artist;
	URL = s_URL;
}

void Song::DisplaySongInfo() { // displays the song name and artist
	cout << name;
	cout << " by " << artist;
}

void Song::PlaySong() { //run a command window to open a chosen browser to open and play the song
	string command;

	// Create Command Line & Call it
	command = "start firefox " + URL;
	const char* system_command = command.c_str();
	system(system_command);

	// Click back into window to continue
	system("pause");

}