#include "employee.h"

#include <string>

using namespace std;

Employee::Employee(const int id, const string& name, Designation designation) : Person(id, name), designation(designation) {}

string Employee::type() const {
    return "Employee";
}