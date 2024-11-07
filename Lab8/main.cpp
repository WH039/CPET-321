/******************************************************/
/*** Title: main.cpp                                ***/
/*** Course: Computational Problem Solving CPET-II  ***/
/*** Developer: Weicheng Haung                      ***/
/*** Description:                                   ***/
/******************************************************/

#include <iostream>
#include <iterator>
#include <set>

#include "sets.h"

using namespace std;

int main()
{
	// Initiates the sets
	set<int> set1 = { 10, 13, 14, 17, 19 };
	set<int> set2 = { 11, 13, 14, 16, 20 };

	//Displaying Set #1
	cout << "Set #1 :" << endl;
	DisplaySet(set1);
	cout << "\n\n";

	//Displaying Set #2
	cout << "Set #2 :" << endl;
	DisplaySet(set2);
	cout << "\n\n";

	//Displays Unified Set
	cout << "Union :" << endl;
	Union(set1, set2);
	cout << "\n\n";
	
	//Displays Intersection Set
	cout << "Intersection :" << endl;
	Intersection(set1, set2);
	cout << "\n\n";

	//Displays Symmetric Set
	cout << "Symmetric Difference :" << endl;
	Symmetric_Difference(set1, set2);
	cout << "\n\n";

	//Displays Difference Set #1 -> Set #2
	cout << "Difference Set #1 -> Set #2 :" << endl;
	Difference(set1, set2);
	cout << "\n\n";

	//Displays Difference Set #2 -> Set #1
	cout << "Difference Set #2 -> Set #1 :" << endl;
	Difference(set2, set1);
	cout << "\n\n";
}