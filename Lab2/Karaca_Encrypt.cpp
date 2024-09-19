#include "Lab2_Functions.h"

string Karaca_Encrypt(string& w) {
	
	string word;
	int wordLength;

	word = w;
	
	//reverses the word
	reverse(word.begin(), word.end());

	//encryption process
	for (char& character : word) {
		if (character == 'a') {
			character = '0';
		}
		else if (character == 'e') {
			character = '1';
		}
		else if (character == 'i') {
			character = '2';
		}
		else if (character == 'o') {
			character = '3';
		}
		else if (character == 'u') {
			character = '4';
		}
		else {
			continue;
		}
	}

	//adds aca to the end
	word += "aca";

	return word;
}