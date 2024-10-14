#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

#include "Accounts.h"
#include "Transactions.h"
#include "Bank.h"
#include "Users.h"
#include "SavingsAccounts.h"
#include "CreditAccounts.h"
#include "TransactionAccounts.h"


using namespace std;


int main() {
    Bank myBank("Global Bank", 1);

    // Predefined users for testing
    vector<Accounts> account1 = {TransactionAccounts("Everyday Transaction Account", 1000, 1000, {})};
    vector<Accounts> account2 = {HighInterestSavings("High Interest Accounts", 2000, 2000, 1.03, 1, 0.4, 1000, {})};
    vector<Accounts> account3 = {TermSavings("Term Savings Acount", 1500, 1500, 1.04, 5, 12, {})}; // TermSavings with a 5-year term

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
        if (cin.fail()) {
            std::cout << "Invalid Choice Please Try Again\n\n";
            cin.clear();
         // discard 'bad' character(s)
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

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
