#include "Lab2_Functions.h"

ifstream OpenInputFile() {
	
	ifstream inFile;
	string filename;
	cout << "Enter the INPUT file named to open: " << endl;
	cin >> filename;

	inFile.open(filename);

	//file open check
	if (!inFile) {
		cout << "Unsuccessfully... Program Terminated" << endl;
		exit(EXIT_FAILURE);
	}

	return inFile;
}