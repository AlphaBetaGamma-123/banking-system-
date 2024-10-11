#include <iostream> 
#include <string> 

using namespace std;


// Derived class TransactionAccount from Accounts
class TransactionAccount : public Accounts {
public:
    // Default constructor
    TransactionAccount() : Accounts() {}

    TransactionAccount(double bal, double funds) : Accounts(bal, funds) {}

    // METHOD. 
    void new_transaction (double amount ) override {
        balance += amount;
        avail_funds += amount;
    }
    
};