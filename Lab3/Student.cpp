#include "Student.h"

using namespace student;

Student::Student(string fn, string ln, double gr) {
	firstName = fn;
	lastName = ln;
	gpa = gr;
}

Student::Student() {
	firstName = "null";
	lastName = "null";
	gpa = 0.0;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

double Student::GetGPA() {
	return gpa;
}