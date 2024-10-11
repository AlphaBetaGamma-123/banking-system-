#include <iostream> 
#include <string> 

using namespace std;


// Class TermSavings (inherits from SavingsAccount)
class TermSavings : public SavingsAccount {
protected:
    int deposit_term;

public:
    // Default constructor
    TermSavings() : SavingsAccount(), deposit_term(0) {}

    // Parameterized constructor
    TermSavings(double bal, double funds, double rate, int period, int term) : SavingsAccount(bal, funds, rate, period), deposit_term(term) {}


};