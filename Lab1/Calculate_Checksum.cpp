//Calculate Checksum Function

#include "Lab1_Functions.h"

int Calculate_Checksum(int CardNumber[]) {
	
	int	output = 0; //finished checksum output
	
	for (int i = 9; i >= 0; i--) {
		i--; //additional increment
		int calcValue = CardNumber[i] * 2; //multiplies each second number in array

		//checks if the number is 10 and above
		if (calcValue >= 10) { 
			calcValue = calcValue - 9; //if number is 10 and above, number is subtracted by 9 to get a single digit number
			CardNumber[i] = calcValue;
		}

		else {
			CardNumber[i] = calcValue;
		}
		
	}

	for (int i = 0; i < 10; i++) { 
		output = output + CardNumber[i]; //adds the change numbers into the output.
	}

	return output;
}