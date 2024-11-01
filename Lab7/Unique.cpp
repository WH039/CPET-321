#include "Unique.h"

ifstream OpenInputFile()
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

int keypad_Encryption(string w){
	int encryptedValue;
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0;

	string word = w;

	for (int i = (word.length() - 1); i >= 0; i--) {
		if (i == 4) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				v5 = 2;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				v5 = 3;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				v5 = 4;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				v5 = 5;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				v5 = 6;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				v5 = 7;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				v5 = 8;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'v' || word[i] == 'z') {
				v5 = 9;
			}
		}
		else if (i == 3) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				v4 = 20;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				v4 = 30;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				v4 = 40;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				v4 = 50;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				v4 = 60;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				v4 = 70;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				v4 = 80;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'v' || word[i] == 'z') {
				v4 = 90;
			}
		}
		else if (i == 2) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				v3 = 200;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				v3 = 300;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				v3 = 400;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				v3 = 500;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				v3 = 600;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				v3 = 700;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				v3 = 800;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'v' || word[i] == 'z') {
				v3 = 900;
			}
		}
		else if (i == 1) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				v2 = 2000;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				v2 = 3000;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				v2 = 4000;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				v2 = 5000;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				v2 = 6000;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				v2 = 7000;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				v2 = 8000;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'v' || word[i] == 'z') {
				v2 = 9000;
			}
		}
		else if (i == 0) {
			if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c') {
				v1 = 20000;
			}
			else if (word[i] == 'd' || word[i] == 'e' || word[i] == 'f') {
				v1 = 30000;
			}
			else if (word[i] == 'g' || word[i] == 'h' || word[i] == 'i') {
				v1 = 40000;
			}
			else if (word[i] == 'j' || word[i] == 'k' || word[i] == 'l') {
				v1 = 50000;
			}
			else if (word[i] == 'm' || word[i] == 'n' || word[i] == 'o') {
				v1 = 60000;
			}
			else if (word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's') {
				v1 = 70000;
			}
			else if (word[i] == 't' || word[i] == 'u' || word[i] == 'v') {
				v1 = 80000;
			}
			else if (word[i] == 'w' || word[i] == 'x' || word[i] == 'y' || word[i] == 'z') {
				v1 = 90000;
			}
		}
	}
	
	encryptedValue = v1 + v2 + v3 + v4 + v5;

	return encryptedValue;
}

void printMultimap(multimap<int, string> mmap)
{
	multimap<int, string>::iterator it1, it2, it3;

	for (int i = 0; i <= 99999; i++) {
		if (mmap.count(i) > 1) {
			it1 = mmap.lower_bound(i);
			it2 = mmap.upper_bound(i);
			cout << "The key " << it1->first << " mapped to " << mmap.count(i) << " words : ";
			for (it3 = it1; it3 != it2; it3++) {
				cout << it3->second << "; ";
			}
			cout << endl;
		}
	}
}



