#include <iostream> 
#include <string> 

using namespace std;


// Class HighInterestSavings (inherits from SavingsAccount)
class HighInterestSavings : public SavingsAccount {
protected:
    //Datamembers. 
    double bonus_interest;
    double prev_period_bal;

public:
    // Default constructor
    HighInterestSavings() : SavingsAccount(), bonus_interest(0.0), prev_period_bal(0.0) {}

    // Parameterized constructor
    HighInterestSavings(double bal, double funds, double rate, int period, double bonus, double prev_bal)
    : SavingsAccount(bal, funds, rate, period), bonus_interest(bonus), prev_period_bal(prev_bal) {}

    
};