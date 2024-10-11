#include <iostream> 
#include <string> 

using namespace std;

// Inhertied from Accounts. 
class SavingsAccount : public Accounts {
protected:
    // Datamembers. 
    double interest_rate;
    int interest_period;

public:
    // Default constructor
    SavingsAccount() : Accounts(), interest_rate(0.0), interest_period(0) {}

    // Parameterized constructor
    SavingsAccount(double bal, double funds, double rate, int period) : Accounts(bal, funds), interest_rate(rate), interest_period(period) {}

    //Method. 
    virtual void add_interest() = 0;
    
};