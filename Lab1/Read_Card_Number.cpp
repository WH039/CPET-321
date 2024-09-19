//Read_Card_Number Function

#include "Lab1_Functions.h"

void Read_Card_Number(int CardNumber[]) {
	
	string CardNumberStr; //input for cardnumbers
	
	bool isNumbers; //check for digits

	cout << "Please Enter Card Number:" << endl;
	cin >> CardNumberStr;

	for (int i = 0; i < 10; i++) {
		isNumbers = isdigit(CardNumberStr[i]); //checks if an input is a number
		if (!isNumbers) {
			break; //if isNumber is false, the check ends and moves on out of loop
		}
	}

	if (!(isNumbers) || CardNumberStr.length() != 10) {
		//not correct length
		while (CardNumberStr.length() != 10) {
			cout << "Please input valid card number length:" << endl;

			cin >> CardNumberStr;
		}
		//not only numbers
		while (isNumbers == false) {
			cout << "Please input only numbers:" << endl;

			cin >> CardNumberStr;

			for (int i = 0; i < 10; i++) { //rechecks if the user inputs numbers
				isNumbers = isdigit(CardNumberStr[i]);
				if (!isNumbers) {
					break;
				}
			}

		}
	}

	cout << "You entered:" << endl;

	for (int i = 0; i < 10; i++) { //add all valid numbers from the string to passby array
		CardNumber[i] = CardNumberStr.at(i) - 48;
		cout << CardNumber[i] << " ";
		
	}

	cout << "\n";

	return;
}