#include "instructor.h"
#include <string>
#include <sstream>
#include <vector>
#include "error.h"
#include "util.h"
#include "serde.h"



using namespace std;

Instructor::Instructor(const int id, const string& name, Designation designation, const string& title) 
    : Employee(id, name, designation), title(title) {}

string Instructor::type() const {
    return "Instructor";
}

string Instructor::serialize() const {
    return to_string(this->getId()) + "|" + 
           this->getName() + "|" + 
           designationStr(this->getdesignation())  + "|" + 
           this->title;
}

Instructor Instructor::deserialize(const string& str) {
    vector<string> parts = strsplit(str, '|');
    if (parts.size() != 4) {
        throw DeserializeErr("Instructor", "Invalid serialized Instructor: " + str);
    }
    int id = stoi(parts[0]);
    string name = parts[1];
    Designation designation = StrtoDesignation(parts[2]);
    string title = parts[3];
    return Instructor(id, name, designation, title);
}