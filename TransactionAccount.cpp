#include "TransactionAccount.h"

TransactionAccount::TransactionAccount() : Accounts() {}

TransactionAccount::TransactionAccount(double bal, double funds) : Accounts(bal, funds) {}

void TransactionAccount::new_transaction(double amount) {
    balance += amount;
    avail_funds += amount;
}

void TransactionAccount::display_account_info() const {
    cout << "Transaction Account Balance: $" << balance << "\n";
}
