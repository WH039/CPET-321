//Check Validity Function

#include "Lab1_Functions.h"

bool Check_Validity(int Check_Sum) {

	bool valid;

	//checks if checksum mods 10
	if (Check_Sum % 10 == 0) {
		valid = true; //successful
	}
	else {
		valid = false; //unsuccessful
	}

	return valid;






}