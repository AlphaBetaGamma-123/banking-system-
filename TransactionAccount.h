#ifndef TRANSACTIONACCOUNT_H
#define TRANSACTIONACCOUNT_H

#include "Accounts.h"

class TransactionAccount : public Accounts {
public:
    TransactionAccount();
    TransactionAccount(double bal, double funds);

    void new_transaction(double amount) override;
    void display_account_info() const override;
};

#endif
