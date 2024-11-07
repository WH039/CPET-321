///**********************************///
// Name      : Weicheng Huang        ///
// File Name : Unique.h              ///
// Course    : CPET 321.01           ///
// Notes     :                       ///
///**********************************///

#pragma once

#include <iostream>
#include <iterator>
#include <fstream>
#include <map>

using namespace std;

// Functions
ifstream OpenInputFile();
int keypad_Encryption(string);
void printMultimap(multimap<int, string>);