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


void Read_Card_Number(int[]);

int Calculate_Checksum(int[]);

bool Check_Validity(int);
