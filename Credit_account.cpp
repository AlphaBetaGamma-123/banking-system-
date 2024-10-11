#include <iostream> 
#include <string> 

using namespace std;

// Class CreditAccount
class CreditAccount : public Accounts {
protected:
    double credit_limit;
    double interest_rate;

public:
    // Default constructor
    CreditAccount() : Accounts(), credit_limit(0.0), interest_rate(0.0) {}

    // Parameterized constructor
    CreditAccount(double bal, double funds, double limit, double rate)
        : Accounts(bal, funds), credit_limit(limit), interest_rate(rate) {}

    // // Placeholder methods
    // void add_interest() {}
    // void change_credit_limit() {}
    // void gen_credit_report() {}

    // Transaction method (override)
    void new_transaction(double amount) override {
        if (balance + amount <= credit_limit) {
            balance += amount;
            avail_funds = credit_limit - balance;
        } else {
            cout << "Transaction exceeds credit limit!\n";
        }
    }

    // Method to add interest
    void add_interest() {
        balance += balance * interest_rate;
    }
};