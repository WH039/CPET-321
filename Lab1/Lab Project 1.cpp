//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                  CPET.321.01.L03
// Name:            Weicheng Huang
// Subject:         Lab 1 Coding Project
// Date:            August 29th, 2024
// Description:     Reviewing and coding in C++ in order to create a Luhn algorithm
// 
// NOTE:            
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <ctime>

#include "Lab1_Functions.h"

using namespace std;

int main()
{
    int CardNumber[10], Check_Sum;
    bool Validity;

    while (1) {
        //Obtains the number entered by the user
        Read_Card_Number(CardNumber);

        //Check_Sum becomes the output that the Calculate_Checksum function gives
        Check_Sum = Calculate_Checksum(CardNumber);

        //Validity becomes the result of the Check_Validity function outputs
        Validity = Check_Validity(Check_Sum);

        if (Validity == true) {
            cout << "Your card is valid" << endl;
        }
        else {
            cout << "Your card is not valid" << endl;
        }
    }

}
