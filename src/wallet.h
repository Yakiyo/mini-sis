#include<student.h>
#include<iostream>
using namespace std;

class Wallet{
    private:
        double balance;
    public:
        Wallet(int bal = 0);

        double getBalance() const;
        void setBalance(double amount);
        Wallet& operator+(double amount);
        Wallet& operator-(double deduct);
        void withdraw(double deduct);
        void deposit(double amount);
};