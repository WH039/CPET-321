#include "Song.h"

using namespace SONG;

Song::Song() {
	
}

Song::Song(string s_name, string s_artist, string s_URL) {
	name   = s_name;
	artist = s_artist;
	URL = s_URL;
}

void Song::DisplaySongInfo() {
	cout << name;
	cout << " by " << artist;
}

void Song::PlaySong() {
	string command;

	// Create Command Line & Call it
	command = "start chrome --window-size=250,675 " + URL;
	const char* system_command = command.c_str();
	system(system_command);

	// Close the Browser Window to Continue
	cout << "\nCLose the Browser Window to Continue, then..." << endl;
	system("pause");

}