#include <iostream>
#include "Bank.h"

class BankTest {
public:
    // Run all tests related to Bank class
    void runTests() {
        testAddUser();
    }

private:
    // Test adding a user to the bank
    void testAddUser() {
        Bank bank("Test Bank", 1, {}, {});
        Users user(1, "John Doe", 'M', "johndoe", "password123", "01/01/1990", {});

        bank.add_user(user);

        if (bank.get_users_arr().size() != 1) {
            std::cout << "Test Add User failed!" << std::endl;
        }
    }
};
