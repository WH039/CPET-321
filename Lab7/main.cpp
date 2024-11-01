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

	input = OpenInputFile();

	while (input >> word) {
		encrypted = keypad_Encryption(word);
		map.insert({ encrypted, word });
	}
	
	printMultimap(map);
}