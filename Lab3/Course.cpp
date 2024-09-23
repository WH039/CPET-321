#include "Student.h"
#include "Course.h"

using namespace course;

Course::Course() {}

void Course::AddStudent(Student stu) {
	roster.push_back(stu);
}

int Course::CourseSize() {
	int classSize;

	classSize = roster.size();

	return classSize;
}

void Course::DropStudent(string ln) {
	for (int i = 0; i < roster.size(); i++) {
		if (roster[i].GetLastName() == ln) {
			roster.erase(roster.begin() + i);
		}
		else {
			continue;
		}
	}
}

Student Course::FindStudentHighestGpa() {
	Student highestGPA = Student("null", "null", 0.0);

	for (int i = 0; i < roster.size(); i++) {
		if (highestGPA.GetGPA() < roster[i].GetGPA()) {
			highestGPA = roster[i];
		}
		else {
			continue;
		}
	}

	return highestGPA;
}

void Course::PrintRoster() {

	for (int i = 0; i < roster.size(); i++) {
		cout << setw(10) << roster[i].GetLastName() << setw(10) << roster[i].GetFirstName() << setw(14) << roster[i].GetGPA() << endl;
	}

	return;
}

vector <Student> Course::GetDeansList() {
	vector <Student> deansList;

	for (int i = 0; i < roster.size(); i++) {
		if (roster[i].GetGPA() >= 3.5) {
			deansList.push_back(roster[i]);
		}
		else {
			continue;
		}
	}

	return deansList;
}