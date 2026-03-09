#include<wallet.h>
#include<error.h>
#include<string.h>

using namespace std;

Wallet :: Wallet(int bal = 0){
    balance = bal;
}

double Wallet :: getBalance() const{    return balance;}
void Wallet :: setBalance(double amount){
    this->balance = amount;
}

void Wallet :: deposit(double amount){
    balance += amount;
}

Wallet& Wallet :: operator+(double amount){
    if(amount <= 0){
        throw TransactionErr("Invalid amount");
    }
    Wallet& temp = *this;
    temp.deposit(amount);
    return temp;
}

void Wallet :: withdraw(double deduct){
    balance -= deduct;
}

Wallet& Wallet :: operator-(double deduct){
    if(balance - deduct < 0){
        throw TransactionErr("Insufficient balance");
    }
    Wallet& temp = *this;
    temp.withdraw(deduct);
    return temp;
}





