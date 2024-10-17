#include "UsersTest.h"
#include "TransactionAccountTest.h"
#include "CreditAccountTest.h"
#include "BankTest.h"

int main() {
    // Run all unit tests for Users class
    UsersTest usersTest;
    usersTest.runTests();

    // Run all unit tests for TransactionAccount class
    TransactionAccountTest transactionAccountTest;
    transactionAccountTest.runTests();

    // Run all unit tests for CreditAccount class
    CreditAccountTest creditAccountTest;
    creditAccountTest.runTests();

    // Run all unit tests for Bank class
    BankTest bankTest;
    bankTest.runTests();

    return 0;
}
