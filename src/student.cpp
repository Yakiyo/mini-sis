#include <string>
#include "student.h"
#include "util.h"
#include "error.h"

using namespace std;

Student :: Student(int id, const string &name, const string &dept) : Person(id, name), dept(dept){}

string Student :: getDept() const {
    return this->dept;
}

void Student :: setDept(const string &dept) {
    this->dept = dept;
}

string Student :: type() const {
    return "Student";
}

string Student :: serialize() const {
    return to_string(this->getId()) + "|" + this->getName() + "|" + this->getDept();
}

Student Student :: deserialize(const string &str) {
    vector<string> parts = strsplit(str, '|');
    if (parts.size() != 3) {
        throw DeserializeErr("Student", "Invalid serialized Student: " + str);
    }
    int id = stoi(parts[0]);
    string name = parts[1];
    string dept = parts[2];
    return Student(id, name, dept);
}