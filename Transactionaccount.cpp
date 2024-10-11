#include <iostream> 
#include <string> 

using namespace std;


// Derived class TransactionAccount from Accounts
class TransactionAccount : public Accounts {
public:
    // Default constructor
    TransactionAccount() : Accounts() {}

    // Parameterized constructor
    TransactionAccount(double bal, double funds) : Accounts(bal, funds) {}

    // Transaction method
    void new_transaction(double amount) override {
        balance += amount;  // Simple addition for deposits (handle withdrawals with conditions)
        avail_funds += amount;
    }
};