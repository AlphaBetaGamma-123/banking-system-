#include <iostream>
#include "Users.h"

class UsersTest {
public:
    // Run all tests related to the Users class
    void runTests() {
        testUserCreation();
        testPasswordChange();
    }

private:
    // Test the creation of a user
    void testUserCreation() {
        Users user(1, "John Doe", 'M', "johndoe", "password123", "01/01/1990", {});

        if (user.get_user_id() != 1 || user.get_full_name() != "John Doe") {
            std::cout << "Test User Creation failed!" << std::endl;
        }
    }

    // Test the ability to change a user's password
    void testPasswordChange() {
        Users user(1, "John Doe", 'M', "johndoe", "password123", "01/01/1990", {});
        user.change_password("newpassword");

        if (user.get_username() != "johndoe" || user.get_username() == "newpassword") {
            std::cout << "Test Password Change failed!" << std::endl;
        }
    }
};
