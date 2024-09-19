#include "Lab2_Functions.h"

string Karaca_Decrypt(string& w) {
	
	string word;
	int wordLength;

	word = w;
	word.erase(word.length() - 3);

	//reversing the word
	reverse(word.begin(), word.end());

	//decryption process
	for (char& character : word) {
		if (character == '0') {
			character = 'a';
		}
		else if (character == '1') {
			character = 'e';
		}
		else if (character == '2') {
			character = 'i';
		}
		else if (character == '3') {
			character = 'o';
		}
		else if (character == '4') {
			character = 'u';
		}
		else {
			continue;
		}
	}

	

	return word;
}