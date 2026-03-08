#include "instructor.h"
#include <string>
using namespace std;

Instructor::Instructor(const int id, const string& name, Designation designation, const string& title) : Employee(id, name, designation), title(title) {}

string Instructor::type() const {
    return "Instructor";
}