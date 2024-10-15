#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>

using namespace std;

class Accounts {
protected:
    double balance;
    double avail_funds;

public:
    Accounts();
    Accounts(double bal, double funds);

    virtual void new_transaction(double amount) = 0;
    virtual void display_account_info() const;
    
    double get_balance() const;
    void set_balance(double new_balance);

    //virtual ~Accounts() = default;
};

#endif
