#pragma once
#include "person.h"
#include "serde.h"

using namespace std;

class Student : public Person, public Serialize, public Deserialize<Student> {
    protected:
    int id;
    string dept;
    string name;
    public:
    Student(int id, const string& name, const string& dept);
    
    void setDept(const string& dept);
    string getDept() const;

    string type() const;
    string serialize() const;
    static Student deserialize(const string& str);

};