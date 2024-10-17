#include <iostream>
#include "CreditAccount.h"

class CreditAccountTest {
public:
    // Run all tests related to CreditAccount
    void runTests() {
        testWithdrawalWithinLimit();
        testWithdrawalExceedLimit();
    }

private:
    // Test withdrawal within the credit limit
    void testWithdrawalWithinLimit() {
        CreditAccount account(1000.0, 1000.0, 5000.0, 0.18);
        account.new_transaction(-3000.0);  // Withdraw 3000 within limit

        if (account.get_balance() != -2000.0) {
            std::cout << "Test Withdrawal Within Limit failed!" << std::endl;
        }
    }

    // Test withdrawal that exceeds the credit limit
    void testWithdrawalExceedLimit() {
        CreditAccount account(1000.0, 1000.0, 5000.0, 0.18);
        account.new_transaction(-6000.0);  // Attempt to withdraw beyond limit

        if (account.get_balance() != 1000.0) {  // Balance should remain unchanged
            std::cout << "Test Withdrawal Exceeding Limit failed!" << std::endl;
        }
    }
};
