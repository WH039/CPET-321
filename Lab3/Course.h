#pragma once

#include "Student.h"

using namespace student;

namespace course {
	class Course {
	private:
		vector <Student> roster;
		Student student;
	public:
		Course();
		void AddStudent(Student);
		int CourseSize();
		void DropStudent(string);
		Student FindStudentHighestGpa();
		void PrintRoster();
		vector <Student> GetDeansList();
	};
}