#include <string>
#include "student.h"

using namespace std;

Student :: Student(int id, const string &name, const string &dept) : Person(id, name), dept(dept){}