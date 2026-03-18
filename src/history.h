#pragma once
#include<iostream>
#include<string>
// #include<wallet.h>
#include<student.h>
#include<dashboard.h>
using namespace std;

class History : public Display{
    public:
        void display() const override;
};