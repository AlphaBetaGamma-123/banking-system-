#include <iostream>
#include "TransactionAccount.h"

class TransactionAccountTest {
public:
    // Run all tests related to TransactionAccount
    void runTests() {
        testDeposit();
        testWithdrawal();
    }

private:
    // Test deposit functionality in TransactionAccount
    void testDeposit() {
        TransactionAccount account(500.0, 500.0);
        account.new_transaction(200.0);  // Deposit 200

        if (account.get_balance() != 700.0) {
            std::cout << "Test Deposit failed!" << std::endl;
        }
    }

    // Test withdrawal functionality in TransactionAccount
    void testWithdrawal() {
        TransactionAccount account(500.0, 500.0);
        account.new_transaction(-100.0);  // Withdraw 100

        if (account.get_balance() != 400.0) {
            std::cout << "Test Withdrawal failed!" << std::endl;
        }
    }
};
