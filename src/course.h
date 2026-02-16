#pragma once

using namespace std;

class Course
{
private:
    string courseID;
    string Title;
    string credits;
    string FacultyName;
    string schedule;

public:
    Course(string courseID, string Title, string credits, string FacultyName);

    string getCourseID() const;

    void setCourseID(const string &courseID);

    string getTitle() const;

    void setTitle(const string &Title);

    string getCredits() const;

    void setCredits(const string &credits);

    string getFacultyName() const;

    void setFacultyName(const string &FacultyName);
};