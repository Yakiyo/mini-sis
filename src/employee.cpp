#include "employee.h"

#include <string>

using namespace std;

Employee::Employee(const int id, const string& name, Designation designation) : Person(id, name), designation(designation) {}

string Employee::type() const {
    return "Employee";
}

string designationStr(Designation desig) {
    switch (desig) {
        case Designation::Faculty:
            return "Faculty";
        case Designation::Admin:
            return "Admin";
        case Designation::Staff:
            return "Staff";
        default:
            return "Unknown";
    }
}