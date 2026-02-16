#pragma once
#include<string>

using namespace std;

class Enrollment {
private:
    string studentID;
    string courseID;
    string grade;
public:
    Enrollment(string studentID, string courseID, string grade);

    string getStudentID() const;

    void setStudentID(const string &studentID);

    string getCourseID() const;

    void setCourseID(const string &courseID);

    string getGrade() const;

    void setGrade(const string &grade);

};