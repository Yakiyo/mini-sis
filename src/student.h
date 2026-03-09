#pragma once
#include "person.h"
#include<wallet.h>
#include "serde.h"

using namespace std;

class Student : public Person, public Serialize, public Deserialize<Student> {
    protected:
    int id;
    string dept;
    string name;
    private:
    Wallet wallet;
    public:
    Student(int id, const string& name, const string& dept, Wallet);
    
    void setDept(const string& dept);
    string getDept() const;

    Wallet getWallet() const;
    void setWallet(Wallet& w);

    string type() const;
    string serialize() const;
    static Student deserialize(const string& str);

};