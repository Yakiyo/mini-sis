#pragma once
#include "employee.h"
#include "serde.h"

using namespace std;



class Instructor: public Employee, public Serialize, public Deserialize<Instructor> {
    private:
    string title;
    public:
    Instructor(const int id, const string& name, Designation designation, const string& title);

    Designation getdesignation() const override;
    void setdesignation(Designation designation) override;
    string type() const override;
    string serialize() const override;
    static Instructor deserialize(const string& str);
};