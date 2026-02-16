#pragma once

#include <string>

class Person {
   protected:
    int id;
    std::string name;

    public:
    Person(int id, const std::string& name);

    int getId() const;
    std::string getName() const;

    virtual std::string type() const;
};