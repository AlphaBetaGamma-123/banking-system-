#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "Accounts.h"

class CreditAccount : public Accounts {
private:
    double credit_limit;
    double interest_rate;

public:
    CreditAccount();
    CreditAccount(double bal, double funds, double limit, double rate);

    void new_transaction(double amount) override;
    void display_account_info() const override;
};

#endif
