#pragma once

#include <string>

using namespace std;

// The base user class
class User {
    // make them protected since every derived classes use them frequently
    protected:
    string name;
    int id;

    public:
    User(const string& name, int id) : name(name), id(id) {}

    virtual string type() const = 0;

    int getId() const;
    virtual string getName() const;
};