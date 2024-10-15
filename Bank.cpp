#include "Bank.h"
#include "TransactionAccount.h"
#include "CreditAccount.h"


Bank::Bank(string name, int id) : bank_name(name), bank_id(id) {}

void Bank::add_user(const Users& user) {
    users_arr.push_back(user);
}

Users* Bank::find_user(const string& username) {
    for (auto& user : users_arr) {
        cout << "Checking user: " << user.get_username() << endl; // Debug output
        if (user.get_username() == username) {
            return &user;
        }
    }
    return nullptr;
}

void Bank::reset_password() {
    string username;
    cout << "Enter your username: ";
    cin >> username;

    Users* user = find_user(username);
    if (!user) {
        cout << "Username not found.\n";
        return;
    }

    cout << user->get_security_question() << "\n";
    cout << "Answer: ";
    string answer;
    cin.ignore();
    getline(cin, answer);

    if (answer == user->get_security_answer()) {
        string new_password;
        cout << "Enter a new password: ";
        cin >> new_password;
        user->change_password(new_password);
        cout << "Password reset successful!\n";
    } else {
        cout << "Incorrect answer. Password reset failed.\n";
    }
}

void Bank::login() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    Users* user = find_user(username);
    if (user && user->get_password() == password) {
        cout << "\nWelcome, " << username << "!\n";
        user->display_user_info();

        int option;
        do {
            cout << "\n1. View Accounts\n2. Deposit\n3. Withdraw\n4. Transfer Funds\n0. Logout\nEnter option: ";
            cin >> option;
            
            if (cin.fail()) { // Check for invalid input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            switch (option) {
                case 1:
                    user->display_user_info();
                    break;
                case 2: {
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    if (cin.fail()) { // Check for invalid input
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid amount. Please try again.\n";
                    } else {
                        user->deposit(amount);
                    }
                    break;
                }
                case 3: {
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid amount. Please try again.\n";
                    } else {
                        user->withdraw(amount);
                    }
                    break;
                }
                case 4: {
                    string receiver_username;
                    double amount;
                    cout << "Enter receiver username: ";
                    cin >> receiver_username;
                    cout << "Receiver entered: " << receiver_username << endl; // Debug output
                    cout << "Enter amount to transfer: ";
                    cin >> amount;
                    
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid amount. Please try again.\n";
                        break;
                    }

                    Users* receiver = find_user(receiver_username);
                    if (receiver) {
                        user->transfer_funds(*receiver, amount);
                    } else {
                        cout << "Receiver not found.\n";
                    }
                    break;
                }
                case 0:
                    cout << "Logging out...\n";
                    break;
                default:
                    cout << "Invalid option. Please choose a valid option.\n";
            }
        } while (option != 0);
    } else {
        cout << "Invalid username or password.\n";
    }
}


void Bank::create_new_user() {
    string username, password, full_name, dob, security_question, security_answer;
    char gender;
    int credit_score;

    cout << "Enter a new username: ";
    cin >> username;

    if (find_user(username)) {
        cout << "Username already exists.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, full_name);
    cout << "Enter gender (M/F): ";
    cin >> gender;
    cout << "Enter date of birth (DD/MM/YYYY): ";
    cin >> dob;
    cout << "Enter an initial credit score: ";
    cin >> credit_score;
    cin.ignore();
    cout << "Enter a security question: ";
    getline(cin, security_question);
    cout << "Enter the answer to your security question: ";
    getline(cin, security_answer);

    shared_ptr<Accounts> account = make_shared<TransactionAccount>(1000, 1000);
    Users newUser(users_arr.size() + 1, full_name, gender, username, password, dob, security_question, security_answer, credit_score, account);
    add_user(newUser);
    cout << "New user created successfully!\n";
}
