#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Accounts.h"

class SavingsAccount : public Accounts {
private:
    double interest_rate;

public:
    SavingsAccount();
    SavingsAccount(double bal, double funds, double rate);

    void new_transaction(double amount) override;
    void add_interest();
    void display_account_info() const override;
};

#endif
