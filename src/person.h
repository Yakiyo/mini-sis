#pragma once

#include <string>

using namespace std;

class Person {
   protected:
    int id;
    string name;

    public:
    Person(int id, const string& name);

    void setId(int id);
    void setName(const string& name);
    int getId() const;
    string getName() const;

    virtual string type() const;
};