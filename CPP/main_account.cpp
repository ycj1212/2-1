#include "pgm_account.h"
#include "account.h"

int main() {
    Account acct1("1234-1234", "Yang", 0);
    Account acct2("5678-5687", "Gang", 0);
    
    acct1.deposit(100000);
    acct1.deposit(200000);
    acct2.deposit(50000);
    acct1.addInterest();
    acct1.addInterest();
    acct1.withdraw(5000);
    acct2.withdraw(10000);

    acct1.display();
    acct2.display();
}