#pragma once

#include <string>

#include "../interface/serde.h"
#include "user.h"

using namespace std;

// An abstract class for employees, inheriting from User. This will be the base class for specific employee types like Teacher and Admin.
class Employee : public User {
   public:
    Employee(const string& name, int id);

    virtual string type() const override = 0;
};

class Admin : public Employee, public Serde<Admin> {
   private:
    string post;

   public:
    Admin(const string& name, int id, const string& post);

    string type() const override;

    string serialize() const override;

    static Admin deserialize(const string& data);
};

class Faculty : public Employee, public Serde<Faculty> {
   private:
    string designation;

   public:
    Faculty(const string& name, int id, const string& designation);

    string type() const override;

    string serialize() const override;

    static Faculty deserialize(const string& data);
};