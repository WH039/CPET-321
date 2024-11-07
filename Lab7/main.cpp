///**********************************///
// Name      : Weicheng Huang        ///
// File Name : main.cpp              ///
// Course    : CPET 321.01           ///
// Notes     :                       ///
///**********************************///

#include <iostream>
#include <iterator>
#include <map>

#include "Unique.h"

int main() {
	ifstream input;
	multimap<int, string> map;
	string word;
	int encrypted;

	input = OpenInputFile(); // Open text file

	while (input >> word) // Reads text file
	{ 
		encrypted = keypad_Encryption(word); // obtains the encrypted number for key value
		map.insert({ encrypted, word }); // adds key and element into multimap
	}
	
	printMultimap(map); // prints multimap 
}