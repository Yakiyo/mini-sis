#pragma once
#include "person.h"

using namespace std;

class Student : public Person {
    protected:
    int id;
    string dept;
    string name;
    public:
    Student(int id, const string& name, const string& dept);
    
    void setDept(const string& dept);
    string getDept() const;

    string type() const;

};