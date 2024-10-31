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