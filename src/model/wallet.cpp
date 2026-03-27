#include "wallet.h"

#include <string>
#include <vector>

#include "../error/error.h"
#include "../interface/serde.h"

using namespace std;

Wallet::Wallet(int studentId, double balance) : studentId(studentId), balance(balance) {}

string Wallet::serialize() const {
    return to_string(studentId) + "," + to_string(balance);
}

Wallet Wallet::deserialize(const string& data) {
    vector<string> parts = strsplit(data, ',');
    if (parts.size() != 2) {
        throw DsrlzExcept("Wallet", data);
    }
    int studentId = stoi(parts[0]);
    double balance = stod(parts[1]);
    return Wallet(studentId, balance);
}

int Wallet::getStudentId() const {
    return studentId;
}

double Wallet::getBalance() const {
    return balance;
}

Wallet& Wallet::operator+(const int amount) {
    this->balance += amount;
    return *this;
}

Wallet& Wallet::operator-(const int amount) {
    if(balance - amount < 0) {
        throw transactionExcept("Insufficient balance");
    }
    this->balance -= amount;
    return *this;
}

// friend function
Wallet& operator-(const int amount,  Wallet& self) {
    if(self.balance - amount < 0) {
        throw transactionExcept("Insufficient balance");
    }
    self.balance -= amount;
    return self;
}

Wallet::operator int() const {
    return studentId;
}
