#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

string Karaca_Encrypt(string&);
string Karaca_Decrypt(string&);
ifstream OpenInputFile();
ofstream OpenOutputFile();
