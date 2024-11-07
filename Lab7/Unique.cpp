///**********************************///
// Name      : Weicheng Huang        ///
// File Name : Unique.cpp            ///
// Course    : CPET 321.01           ///
// Notes     :                       ///
///**********************************///

#include "Unique.h"

ifstream OpenInputFile() // Opens Text File
{
	ifstream inFile;
	string filename = "words.txt";

	inFile.open(filename);

	//file open check
	if (!inFile) {
		cout << "Unsuccessfully... Program Terminated" << endl;
		exit(0);
	}
	
	return inFile;
}

int keypad_Encryption(string w) // Encryption Method with ints
{
	//Variables
	int encryptedValue; // Final encrypted number
	int encryptedPosition1 = 0; // Letter position 1
	int encryptedPosition2 = 0; // Letter position 2
	int encryptedPosition3 = 0; // Letter position 3
	int encryptedPosition4 = 0; // Letter position 4
	int encryptedPosition5 = 0; // Letter position 5

	string word = w; 

	// Encryption
	for (int i = (word.length() - 1); i >= 0; i--) {
		if (i == 4) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				encryptedPosition5 = 2;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				encryptedPosition5 = 3;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				encryptedPosition5 = 4;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				encryptedPosition5 = 5;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				encryptedPosition5 = 6;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				encryptedPosition5 = 7;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				encryptedPosition5 = 8;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'v' || word[i] == 'z') {
				encryptedPosition5 = 9;
			}
		}
		else if (i == 3) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				encryptedPosition4 = 20;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				encryptedPosition4 = 30;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				encryptedPosition4 = 40;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				encryptedPosition4 = 50;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				encryptedPosition4 = 60;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				encryptedPosition4 = 70;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				encryptedPosition4 = 80;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'v' || word[i] == 'z') {
				encryptedPosition4 = 90;
			}
		}
		else if (i == 2) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				encryptedPosition3 = 200;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				encryptedPosition3 = 300;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				encryptedPosition3 = 400;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				encryptedPosition3 = 500;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				encryptedPosition3 = 600;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				encryptedPosition3 = 700;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				encryptedPosition3 = 800;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'v' || word[i] == 'z') {
				encryptedPosition3 = 900;
			}
		}
		else if (i == 1) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				encryptedPosition2 = 2000;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				encryptedPosition2 = 3000;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				encryptedPosition2 = 4000;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				encryptedPosition2 = 5000;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				encryptedPosition2 = 6000;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				encryptedPosition2 = 7000;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				encryptedPosition2 = 8000;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'v' || word[i] == 'z') {
				encryptedPosition2 = 9000;
			}
		}
		else if (i == 0) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				encryptedPosition1 = 20000;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				encryptedPosition1 = 30000;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				encryptedPosition1 = 40000;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				encryptedPosition1 = 50000;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				encryptedPosition1 = 60000;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				encryptedPosition1 = 70000;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				encryptedPosition1 = 80000;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'y' || word[i] == 'z') {
				encryptedPosition1 = 90000;
			}
		}
	}
	
	// Combines values
	encryptedValue = encryptedPosition1 + encryptedPosition2 + encryptedPosition3 + encryptedPosition4 + encryptedPosition5;

	return encryptedValue;
}

void printMultimap(multimap<int, string> mmap) // Prints the multimap
{
	multimap<int, string>::iterator it1, it2, it3;

	for (int i = 0; i <= 99999; i++) { // Loops for every possible combination of words.
		if (mmap.count(i) > 1) { // Detects if the key has more than one element
			it1 = mmap.lower_bound(i);
			it2 = mmap.upper_bound(i);
			cout << "The key " << it1->first << " mapped to " << mmap.count(i) << " words : "; // Prints the key value
			for (it3 = it1; it3 != it2; it3++) {
				cout << it3->second << "; "; // Prints element
			}
			cout << endl;
		}
	}
}



