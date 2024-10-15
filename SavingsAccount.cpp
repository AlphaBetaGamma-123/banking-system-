#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : Accounts(), interest_rate(0.02) {}

SavingsAccount::SavingsAccount(double bal, double funds, double rate) : Accounts(bal, funds), interest_rate(rate) {}

void SavingsAccount::new_transaction(double amount) {
    if (balance + amount >= 0) {
        balance += amount;
        avail_funds = balance;
    } else {
        cout << "Insufficient funds for this transaction.\n";
    }
}

void SavingsAccount::add_interest() {
    balance += balance * interest_rate;
    avail_funds = balance;
    cout << "Interest added. New balance: $" << balance << "\n";
}

void SavingsAccount::display_account_info() const {
    cout << "Savings Account Balance: $" << balance << " (Interest Rate: " << interest_rate * 100 << "%)\n";
}
