/******************************************************/
/*** Title: Song.h                                  ***/
/*** Course: Computational Problem Solving CPET-II  ***/
/*** Developer: Weicheng Huang                      ***/
/*** Description: Header file for class Song        ***/
/******************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

namespace SONG {
	class Song {
	private:
		string name;
		string artist;
		string URL;

	public:
		Song(string, string, string);
		Song();
		void DisplaySongInfo();
		void PlaySong();
	};
}