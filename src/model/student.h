#pragma once

#include <string>
#include <vector>
#include "user.h"
#include "../interface/serde.h"
#include "../error/error.h"

using namespace std;

// The student class, inheriting from User and implementing serialization and deserialization
class Student : public User, public Serde<Student> {
    private:
    string dept;
    int batch;
    public:
    Student(const string& name, int id, const string& dept, int batch);

    string type() const override;

    string serialize() const override;

    static Student deserialize(const string& data);
};
