#pragma once

#include <iostream>
#include <iterator>
#include <fstream>
#include <map>

using namespace std;

ifstream OpenInputFile();
int keypad_Encryption(string);
void printMultimap(multimap<int, string>);