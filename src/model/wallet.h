#pragma once

#include <string>
#include <vector>

#include "../interface/serde.h"

using namespace std;

class Wallet : public Serde<Wallet> {
   private:
    int studentId;
    double balance;

   public:
    Wallet(int studentId, double balance);

    string serialize() const override;
    static Wallet deserialize(const string& data);

    int getStudentId() const;
    double getBalance() const;

    Wallet& operator+(const int amount);

    friend Wallet& operator-(const int amount, Wallet& self);
    Wallet& operator-(const int amount);

    operator int() const;

    void addMoney(int amount);
    void withdrawMoney(int amount);
};