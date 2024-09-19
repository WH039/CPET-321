#include "Lab2_Functions.h"

ofstream OpenOutputFile() {
	
	ofstream outFile;
	string filename;

	cout << "Enter the OUTPUT file named to open: " << endl;
	cin >> filename;

	outFile.open(filename);
	
	//file open check
	if (!outFile) {
		cout << "Unsuccessfully... Program Terminated" << endl;
		exit(EXIT_FAILURE);
	}
	
	return outFile;
}