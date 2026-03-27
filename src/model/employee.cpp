#include "employee.h"

#include <stdexcept>
#include <string>

#include "../error/error.h"

using namespace std;

// Employee class implementation
Employee::Employee(const string& name, int id)
    : User(name, id) {}



// Admin class implementation

Admin::Admin(const string& name, int id, const string& post)
    : Employee(name, id), post(post) {}

string Admin::type() const {
    return "Admin";
}

string Admin::serialize() const {
    return type() + "," + name + "," + to_string(id) + "," + post;
}

Admin Admin::deserialize(const string& data) {
    vector<string> parts = strsplit(data, ',');

    if (parts.size() != 4 || parts[0] != "Admin") {
        throw DsrlzExcept("Admin", data);
    }
    return Admin(parts[1], stoi(parts[2]), parts[3]);
}

string Admin::getName() const {
    return name + " (" + post + ")";
}



// Faculty class implementation

Faculty::Faculty(const string& name, int id, const string& designation)
    : Employee(name, id), designation(designation) {}

string Faculty::type() const {
    return "Faculty";
}

string Faculty::serialize() const {
    return type() + "," + name + "," + to_string(id) + "," + designation;
}

Faculty Faculty::deserialize(const string& data) {
    vector<string> parts = strsplit(data, ',');

    if (parts.size() != 4 || parts[0] != "Faculty") {
        throw DsrlzExcept("Faculty", data);
    }
    return Faculty(parts[1], stoi(parts[2]), parts[3]);
}

string Faculty::getName() const {
    return designation + " " + name;
}