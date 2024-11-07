/******************************************************/
/*** Title: sets.h                                  ***/
/*** Course: Computational Problem Solving CPET-II  ***/
/*** Developer: Weicheng Haung                      ***/
/*** Description:                                   ***/
/******************************************************/
#pragma once

#include <iostream>
#include <iterator>
#include <iomanip>
#include <set>

using namespace std;

void DisplaySet(set<int>);
void Union(set<int>, set<int>);
void Intersection(set<int>, set<int>);
void Symmetric_Difference(set<int>, set<int>);
void Difference(set<int>, set<int>);