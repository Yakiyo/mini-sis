#include "student.h"
#include <string>

#include "error.h"
#include "util.h"

using namespace std;

Student ::Student(int id, const string& name, const string& dept, Wallet w) : Person(id, name), dept(dept), wallet(w) {}

string Student ::getDept() const {
    return this->dept;
}
void Student ::setAcademicYear(const string& year) {
    this->AcademicYear = year;
}
void Student ::setSemester(int semester) {
    this->Semester = semester;
}
string Student ::getAcademicYear() const {
    return this->AcademicYear;
}
int Student ::getSemester() const {
    return this->Semester;
}

void Student ::setDept(const string& dept) {
    this->dept = dept;
}

void Student :: setWallet(Wallet& w){
    this->wallet = w;
}

Wallet Student :: getWallet() const{
    return wallet;
}

string Student ::type() const {
    return "Student";
}

string Student ::serialize() const {
    return to_string(this->getId()) + "|" + this->getName() + "|" + this->getDept();
}

Student Student ::deserialize(const string& str) {
    vector<string> parts = strsplit(str, '|');
    if (parts.size() != 3) {
        throw DeserializeErr("Student", "Invalid serialized Student: " + str);
    }
    int id = stoi(parts[0]);
    string name = parts[1];
    string dept = parts[2];
    return Student(id, name, dept, Wallet());
}