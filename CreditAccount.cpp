#include "CreditAccount.h"

CreditAccount::CreditAccount() : Accounts(), credit_limit(0.0), interest_rate(0.0) {}

CreditAccount::CreditAccount(double bal, double funds, double limit, double rate)
    : Accounts(bal, funds), credit_limit(limit), interest_rate(rate) {}

void CreditAccount::new_transaction(double amount) {
    if (balance + amount <= credit_limit) {
        balance += amount;
        avail_funds = credit_limit - balance;
    } else {
        cout << "Transaction exceeds credit limit!\n";
    }
}

void CreditAccount::display_account_info() const {
    cout << "Credit Account Balance: $" << balance << " (Limit: $" << credit_limit << ")\n";
}
