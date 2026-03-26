#include "student.h"

#include <string>
#include <vector>

#include "../error/error.h"
#include "../interface/serde.h"
#include "user.h"

using namespace std;

Student::Student(const string& name, int id, const string& dept, int batch) : User(name, id), dept(dept), batch(batch) {}

string Student::type() const {
    return "Student";
}

string Student::serialize() const {
    return type() + "," + name + "," + to_string(id) + "," + dept + "," + to_string(batch);
}

Student Student::deserialize(const string& data) {
    vector<string> parts = strsplit(data, ',');
    
    if (parts.size() != 5 || parts[0] != "Student") {
        throw DsrlzExcept("Student", data);
    }
    // stoi - string to int, used for id and batch
    return Student(parts[1], stoi(parts[2]), parts[3], stoi(parts[4]));
}

