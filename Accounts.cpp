#include "Accounts.h"

Accounts::Accounts() : balance(0.0), avail_funds(0.0) {}

Accounts::Accounts(double bal, double funds) : balance(bal), avail_funds(funds) {}

void Accounts::display_account_info() const {
    cout << "Balance: $" << balance << "\n";
}

double Accounts::get_balance() const { return balance; }

void Accounts::set_balance(double new_balance) { balance = new_balance; }
