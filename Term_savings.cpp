#include <iostream> 
#include <string> 

using namespace std;


// Class TermSavings (inherits from SavingsAccount)
class TermSavings : public SavingsAccount {
protected:
    // Datmembers. 
    int deposit_term;

public:
    // Default constructor
    TermSavings() : SavingsAccount(), deposit_term(0) {}

    // Parameterized constructor
    TermSavings(double bal, double funds, double rate, int period, int term) : SavingsAccount(bal, funds, rate, period), deposit_term(term) {}

    // Methods. 
    // Override method. 
    void add_bonus_interest () override {
        balance += balance * interest_rate;
    }

    void chnage_term(int_term) {deposit_term = new_term; }

};