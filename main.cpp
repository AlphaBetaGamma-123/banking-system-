#include <iostream>
#include <memory>
#include "Bank.h"
#include "Users.h"
#include "TransactionAccount.h"
#include "CreditAccount.h"
#include "SavingsAccount.h"
#include "Accounts.h"



using namespace std;

int main() {
    Bank myBank("Global Bank", 1);

    shared_ptr<Accounts> account1 = make_shared<TransactionAccount>(1000, 1000);
    shared_ptr<Accounts> account2 = make_shared<TransactionAccount>(2000, 2000);
    shared_ptr<Accounts> account3 = make_shared<CreditAccount>(0, 0, 5000, 0.15);

    Users user1(1, "John Doe", 'M', "a", "b", "15/04/1995", "What is your favorite color?", "blue", 750, account1);
    Users user2(2, "User Two", 'M', "c", "d", "01/01/1990", "What is your pet's name?", "buddy", 700, account2);
    Users user3(3, "Charlie Brown", 'M', "x", "y", "23/08/1988", "What is your mother's maiden name?", "smith", 650, account3);
    
    myBank.add_user(user1);
    myBank.add_user(user2);
    myBank.add_user(user3);

    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. Login\n";
        cout << "2. Create New User\n";
        cout << "3. Reset Password\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myBank.login();
                break;
            case 2:
                myBank.create_new_user();
                break;
            case 3:
                myBank.reset_password();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
