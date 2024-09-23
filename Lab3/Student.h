#pragma once
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

namespace student{
	class Student {
	private:
		string firstName;
		string lastName;
		double gpa;

	public:
		Student(string, string, double);
		Student();
		string GetFirstName();
		string GetLastName();
		double GetGPA();
	};
}