#include "Course.h"
#include "Student.h"
//#include "Course.cpp"
//#include "Student.cpp"
using namespace std;
using namespace course;
using namespace student;

int main() {

    /*** Misc Output Formating ***/
    cout << fixed << left << setprecision(2);
    
    /*** Step #1 ***/
    cout << "\n\nStep #1 : Creating Students and Printing Their Information\n" << endl;

    Student S1("Mary", "Smith", 3.52);
    Student S2("Amy", "Jones", 2.57);

    cout << setw(7) << S1.GetLastName() <<  
            setw(7) << S1.GetFirstName() << 
            setw(7) << S1.GetGPA() << endl;

    cout << setw(7) << S2.GetLastName() <<
            setw(7) << S2.GetFirstName() <<
            setw(7) << S2.GetGPA() << endl;
    /***************/


    /*** Step #2 ***/
    cout << "\n\nStep #2 : Adding Students to a Course and Printing Course Size\n" << endl;
    Course CPET_321;
    int courseSize;

    CPET_321.AddStudent(S1);
    CPET_321.AddStudent(S2);

    courseSize = CPET_321.CourseSize();
    cout << "Course size: " << CPET_321.CourseSize() << " students" << endl;

    CPET_321.AddStudent(Student("John", "Adams", 2.29));
    CPET_321.AddStudent(Student("Karen", "Lake", 3.69));
    cout << "Course size: " << CPET_321.CourseSize() << " students" << endl;

    CPET_321.AddStudent(Student("Henry", "Nguyen", 3.58));
    CPET_321.AddStudent(Student("Brenda", "Stern", 2.60));
    CPET_321.AddStudent(Student("Lynda", "Robby", 2.12));
    CPET_321.AddStudent(Student("Sonya", "King", 2.39));
    cout << "Course size: " << CPET_321.CourseSize() << " students" << endl;
    /***************/


    /*** Step #3 ***/
    cout << "\n\nStep #3 : Dropping (2) Students from a Course and Printing Course Size\n" << endl;
    string dropName;
    
    dropName = "Adams";
    cout << "Dropping " << dropName << endl;
    CPET_321.DropStudent(dropName);
    cout << "Course size: " << CPET_321.CourseSize() << " students" << endl;

    dropName = "Stern";
    cout << "Dropping " << dropName << endl;
    CPET_321.DropStudent(dropName);
    cout << "Course size: " << CPET_321.CourseSize() << " students" << endl;
    /***************/


    /*** Step #4 ***/
    cout << "\n\nStep #4 : Finding Students with highest GPA and Printing Their Information\n" << endl;
    Student S3;
    S3 = CPET_321.FindStudentHighestGpa();
    cout << "Top student: " <<
            setw(7) << S3.GetLastName() <<
            setw(7) << S3.GetFirstName() <<
            setw(7) << S3.GetGPA() << endl;

    dropName = S3.GetLastName();
    cout << "Dropping " << dropName << endl;
    CPET_321.DropStudent(dropName);
    cout << "Course size: " << CPET_321.CourseSize() << " students" << endl;
    S3 = CPET_321.FindStudentHighestGpa();
    cout << "Top student: " << 
             setw(7) << S3.GetLastName() <<
             setw(7) << S3.GetFirstName() <<
             setw(7) << S3.GetGPA() << endl;
    /***************/


    /*** Step #5 ***/   
    cout << "\n\nStep #5 : Adding Four Students then Printing the Course Roster\n" << endl;
    CPET_321.AddStudent(Student("Henry", "Cabot", 3.56));
    CPET_321.AddStudent(Student("Brenda", "Stern", 2.14));
    CPET_321.AddStudent(Student("Jane", "Flynn", 3.91));
    CPET_321.AddStudent(Student("Rob", "Lowe", 3.26));
    CPET_321.PrintRoster();
    /***************/


    /*** Step #6 ***/
    cout << "\n\nStep #6 : Prints Dean's List\n" << endl;
    vector<Student> deanList;
    deanList = CPET_321.GetDeansList();
    cout << fixed << setprecision(2);
    for (Student student : deanList) {
        cout << setw(7) << student.GetLastName() <<
                setw(7) << student.GetFirstName() <<
                setw(7) << student.GetGPA() << endl;
    }
    /***************/

    return 0;
}