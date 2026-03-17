#pragma once
#include<student.h>
#include<iostream>
#include<string>
using namespace std;

class Dashboard{
    private:
        Student stud;
    public:
        void setStudent(const Student& stud);
        void displayStudent() const;

        void displayWallet() const;
};