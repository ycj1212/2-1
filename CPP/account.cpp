#include "pgm_account.h"
#include "account.h"

Account::Account(string num, string nm, int bal) {
    number = num;
    name = nm;
    balance = bal;
}

int Account::deposit(int money) {
    balance += money;
    return balance;
}

int Account::withdraw(int money) {
    balance -= money;
    return balance;
}

int Account::addInterest() {
    balance = balance + (balance * 0.035);
    return balance;
}

void Account::display() {
    cout << "계좌번호: " << number << endl;
    cout << "이    름 : " << name << endl;
    cout << "잔    고 : " << balance << "\n" << endl;
}