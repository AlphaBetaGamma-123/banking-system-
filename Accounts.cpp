#include <iostream> 
#include <string> 

using namespace std;

class Accounts {
protected:
    // Datamembers. 
    double balance;
    double avail_funds;

public:
    // Default constructor
    Accounts() : balance(0.0), avail_funds(0.0) {}

    // Parameterized constructor
    Accounts(double bal, double funds) : balance(bal), avail_funds(funds) {}

    // Pure virtual method (Abstract class)
    virtual void new_transaction() = 0;

    // Getter methods. 
    double get_balance () const {return balance; }
    double get_avail_funds () {return avail_funds; }

    // // Virtual destructor.
    // virtual ~Accounts() = default;
};