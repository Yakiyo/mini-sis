#include "person.h"
#include<string>

class Employee: Person {
    private:
        Designation designation;
public:
    Employee(const int id, const string &name, Designation designation);
    string type() const override;
};

enum class Designation {
    Faculty,
    Admin,
    Staff
};