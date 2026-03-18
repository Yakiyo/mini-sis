#pragma once
#include<iostream>
#include<string>
#include<student.h>
using namespace std;

class Display{
    protected:
        Student stud;
    private:
        void setStudent(const Student& stud);
        
        virtual void display() const = 0;
        virtual ~Display() = default; // what does it do?
};