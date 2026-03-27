#include "grade.h"

#include <string>

#include "../error/error.h"
#include "../interface/serde.h"

using namespace std;

Grade::Grade(string courseCode, string grade, int studentId)
    : courseCode(courseCode), grade(grade), studentId(studentId) {}

string Grade::serialize() const {
    return courseCode + "," + grade + "," + to_string(studentId);
}

Grade Grade::deserialize(const string& data) {
    vector<string> parts = strsplit(data, ',');
    if (parts.size() != 3) {
        throw DsrlzExcept("Grade", data);
    }
    string courseCode = parts[0];
    string grade = parts[1];
    int studentId = stoi(parts[2]);
    return Grade(courseCode, grade, studentId);
}

int Grade::getStudentId() const {
    return studentId;
}

string Grade::getCourseCode() const {
    return courseCode;
}

string Grade::getGrade() const {
    return grade;
}
