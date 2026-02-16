#include<course.h>
#include<string>

Course::Course(string courseID, string Title, string credits, string FacultyName)
{
    this->courseID = courseID;
    this->Title = Title;
    this->credits = credits;
    this->FacultyName = FacultyName;
}

string Course::getCourseID() const
{
    return courseID;
}

void Course::setCourseID(const string &courseID)
{
    this->courseID = courseID;
}

string Course::getTitle() const
{
    return Title;
}

void Course::setTitle(const string &Title)
{
    this->Title = Title;
}

string Course::getCredits() const
{
    return credits;
}

void Course::setCredits(const string &credits)
{
    this->credits = credits;
}

string Course::getFacultyName() const
{
    return FacultyName;
}

void Course::setFacultyName(const string &FacultyName)
{
    this->FacultyName = FacultyName;
}

