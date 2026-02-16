#include<enrollment.h>
#include<string>

using namespace std;

Enrollment::Enrollment(string studentID, string courseID, string grade)
{
    this->studentID = studentID;
    this->courseID = courseID;
    this->grade = grade;
}

string Enrollment::getStudentID() const
{
    return studentID;
}

void Enrollment::setStudentID(const string &studentID)
{
    this->studentID = studentID;
}

string Enrollment::getCourseID() const
{
    return courseID;
}

void Enrollment::setCourseID(const string &courseID)
{
    this->courseID = courseID;
}

string Enrollment::getGrade() const
{
    return grade;
}

void Enrollment::setGrade(const string &grade)
{
    this->grade = grade;
}


