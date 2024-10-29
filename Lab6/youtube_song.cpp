/******************************************************/
/*** Title: youtube_song.cpp                        ***/
/*** Course: Computational Problem Solving CPET-II  ***/
/*** Developer: Dr G.H. Zion                        ***/
/*** Description: Play a song from youtube URL      ***/
/******************************************************/
#include <iostream>
#include <string>

using namespace std;

int main()
{

	string song_Name   = "Highway to Hell";
	string song_Artist = "AC / DC ";
	string song_URL    = "https://youtu.be/5HYT9iEM1Ig";

	string command;

	cout << "Playing : " << song_Name;
	cout << " by " << song_Artist << endl;

	// Create Command Line & Call it
	command = "start chrome --window-size=250,675 " + song_URL;
	const char* system_command = command.c_str();
	system(system_command);

	// Close the Browser Window to Continue
	cout << "\nCLose the Browser Window to Continue, then..." << endl;
	system("pause");

	cout << "Bye, Thanks For Playing" << endl;

	return 0;
}