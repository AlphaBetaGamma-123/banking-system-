#include <iostream> 
#include <string> 

using namespace std;

// Class BusinessTransaction (inherits from TransactionAccount)
class BusinessTransaction : public Accounts {
protected:
    int abn;
    string business_name;

public:
    // Default constructor
    BusinessTransaction() : Accounts(), abn(0), business_name("No Business Name") {}

    // Parameterized constructor
    BusinessTransaction(double bal, double funds, int abn_num, string biz_name)
        : Accounts(bal, funds), abn(abn_num), business_name(biz_name) {}

    // Placeholder method
    void deposit_eftpos() {}
};