/******************************************************/
/*** Title: sets.cpp                                ***/
/*** Course: Computational Problem Solving CPET-II  ***/
/*** Developer: Weicheng Haung                      ***/
/*** Description:                                   ***/
/******************************************************/

#include "sets.h"

void DisplaySet(set<int> s) {
	for (auto it : s) { // prints out all elements of the set
		cout << it << "," << setw(4);
	}
}

void Union(set<int> s1, set<int> s2) {
	set<int> unifiedSet;

	for (auto it : s1) { // inserts values from the first set into the combined set
		unifiedSet.insert(it);
	}

	for (auto it : s2) { // inserts values from the second set into the combined set
		unifiedSet.insert(it);
	}
	
	for (auto it : unifiedSet) { // prints the output set
		cout << it << "," << setw(4);
	}
}

void Intersection(set<int>s1, set<int> s2) {
	set<int> intersecting;

	for (auto it1 : s1) { 
		if (s2.find(it1) != s2.end()) { // checks to see if an element in a set is present in other set
			intersecting.insert(it1);   // if present the element is then added into output set
		}
	}

	for (auto it : intersecting) { // prints the output set
		cout << it << "," << setw(4);
	}
}

void Symmetric_Difference(set<int> s1, set<int> s2) {
	set<int> symmetric;

	for (auto it : s1) {
		if (s2.find(it) != s2.end()) { // checks to see if an element in a set is present in other set
			continue;                   // if present the element is skipped
		}
		else { // if not present it adds to the output set
			symmetric.insert(it);
		}
	}

	for (auto it : s2) {
		if (s1.find(it) != s1.end()) { // checks to see if an element in a set is present in other set
			continue;                  // if present the element is skipped
		}
		else { // inserts elements not present
			symmetric.insert(it);
		}
	}

	for (auto it : symmetric) { // prints the output set
		cout << it << "," << setw(4);
	}
}

void Difference(set<int> s1, set<int> s2) {
	set<int> difference;

	for (auto it : s1) {
		if (s2.find(it) != s2.end()) { // checks to see if an element in a set is present in other set
			continue;                  // if present the element is skipped
		}
		else { // inserts elements not present
			difference.insert(it); 
		}
	}

	for (auto it : difference) { // prints the output set
		cout << it << "," << setw(4);
	}
}