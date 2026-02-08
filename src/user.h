#pragma once

#include <string>

class User {
   protected:
    int id;
    std::string name;

    public:
    User(int id, const std::string& name);

    int getId() const;
    std::string getName() const;

    virtual std::string type() const;
};