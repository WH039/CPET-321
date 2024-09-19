//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                  CPET.321.01.L03
// Name:            Weicheng Huang
// Subject:         Lab 2 Coding Project
// Date:            August 29th, 2024
// Description:     Creating a Karaca's Encryption Algorithm in C++
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
#include <cmath>

#include "Lab2_Functions.h"

using namespace std;

int main()
{
    //variables
    ifstream inputFile;
    ofstream outputFile;
    string word, changedWord;
    char encryptOrDecrypt;

    //calls the functions to open an input and output file
    inputFile = OpenInputFile();
    outputFile = OpenOutputFile();

    //asks user for encryption or decryption
    cout << "Encrypt or Decrypt, input E or D" << endl;
    cin >> encryptOrDecrypt;
    encryptOrDecrypt = toupper(encryptOrDecrypt);
    
    //checks in case the user input wrong character
    if (encryptOrDecrypt != 'E' && encryptOrDecrypt != 'D') {
        cout << "Option Not Available" << endl;
    }

    //encryption and decryption
    while (inputFile >> word) {
        if (encryptOrDecrypt == 'E') {
            changedWord = Karaca_Encrypt(word);
        }
        else if (encryptOrDecrypt == 'D') {
            changedWord = Karaca_Decrypt(word);
        }
        outputFile << changedWord << endl;
    }

    //closing both input and output files
    inputFile.close();
    outputFile.close();
    
    //last check for if the code ran correctly
    cout << "It worked?" << endl;

}
