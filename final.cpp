#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

// Base class for accounts
class Accounts {
protected:
    double balance;
    double avail_funds;

public:
    Accounts() : balance(0.0), avail_funds(0.0) {}
    Accounts(double bal, double funds) : balance(bal), avail_funds(funds) {}
    virtual void new_transaction(double amount) = 0;
    virtual void display_account_info() const {
        cout << "Balance: $" << balance << "\n";
    }
    virtual ~Accounts() = default;
};

// Derived class for transaction accounts
class TransactionAccount : public Accounts {
public:
    TransactionAccount() : Accounts() {}
    TransactionAccount(double bal, double funds) : Accounts(bal, funds) {}
    void new_transaction(double amount) override {
        balance += amount;
        avail_funds += amount;
    }
    void display_account_info() const override {
        cout << "Transaction Account Balance: $" << balance << "\n";
    }
};

// Derived class for credit accounts
class CreditAccount : public Accounts {
private:
    double credit_limit;
    double interest_rate;

public:
    CreditAccount() : Accounts(), credit_limit(0.0), interest_rate(0.0) {}
    CreditAccount(double bal, double funds, double limit, double rate)
        : Accounts(bal, funds), credit_limit(limit), interest_rate(rate) {}

    void new_transaction(double amount) override {
        if (balance + amount <= credit_limit) {
            balance += amount;
            avail_funds = credit_limit - balance;
        } else {
            cout << "Transaction exceeds credit limit!\n";
        }
    }

    void display_account_info() const override {
        cout << "Credit Account Balance: $" << balance << " (Limit: $" << credit_limit << ")\n";
    }
};

// User class for managing user information and accounts
class Users {
private:
    int user_id;
    string full_name;
    char gender;
    string username;
    string password;
    string dob;
    string security_question;
    string security_answer;
    int credit_score;
    vector<shared_ptr<Accounts>> accounts;

public:
    Users(int id, string name, char g, string user, string pass, string birthdate, string sec_question, string sec_answer, int score)
        : user_id(id), full_name(name), gender(g), username(user), password(pass), dob(birthdate), security_question(sec_question), security_answer(sec_answer), credit_score(score) {}

    string get_username() const { return username; }
    string get_password() const { return password; }
    string get_security_question() const { return security_question; }
    string get_security_answer() const { return security_answer; }
    int get_credit_score() const { return credit_score; }
    
    void change_password(string new_pass) { password = new_pass; }

    void display_user_info() const {
        cout << "User ID: " << user_id << "\nFull Name: " << full_name << "\n";
        cout << "DOB: " << dob << "\n";
        cout << "Number of Accounts: " << accounts.size() << "\n";
    }

    void display_accounts() const {
        if (accounts.empty()) {
            cout << "No accounts available.\n";
            return;
        }
        for (size_t i = 0; i < accounts.size(); ++i) {
            cout << i + 1 << ". ";
            accounts[i]->display_account_info();
        }
    }

    void add_account(shared_ptr<Accounts> account) {
        accounts.push_back(account);
    }
};

// Bank class to manage all users and facilitate bank operations
class Bank {
private:
    string bank_name;
    int bank_id;
    vector<Users> users_arr;

public:
    Bank(string name, int id) : bank_name(name), bank_id(id) {}

    void add_user(const Users& user) {
        users_arr.push_back(user);
    }

    Users* find_user(const string& username) {
        for (auto& user : users_arr) {
            if (user.get_username() == username) {
                return &user;
            }
        }
        return nullptr;
    }
};

// Function to reset a user's password
void reset_password(Bank& bank) {
    string username;
    cout << "Enter your username: ";
    cin >> username;

    Users* user = bank.find_user(username);
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

// Function to allow a user to apply for a loan
void apply_for_loan(Users* user) {
    int credit_score = user->get_credit_score();
    cout << "Your credit score is: " << credit_score << "\n";

    if (credit_score < 600) {
        cout << "Sorry, you are not eligible for a loan.\n";
        return;
    }

    double interest_rate;
    if (credit_score >= 800) interest_rate = 0.05;
    else if (credit_score >= 700) interest_rate = 0.1;
    else interest_rate = 0.15;

    double loan_amount;
    cout << "Enter the loan amount you want to borrow: ";
    cin >> loan_amount;

    int loan_term;
    cout << "Choose loan term:\n1. 10 years\n2. 20 years\n3. 30 years\n";
    cout << "Enter your choice: ";
    cin >> loan_term;

    int years = (loan_term == 1) ? 10 : (loan_term == 2) ? 20 : 30;
    double total_repayment = loan_amount * pow(1 + interest_rate, years);
    cout << "Your total repayment over " << years << " years is $" << total_repayment << "\n";
}

// Function to log in a user
void login(Bank& bank) {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    Users* user = bank.find_user(username);
    if (user && user->get_password() == password) {
        cout << "\nWelcome, " << username << "!\n";
        user->display_user_info();

        int option;
        do {
            cout << "\n1. Apply for Loan\n0. Logout\nEnter option: ";
            cin >> option;
            if (option == 1) apply_for_loan(user);
        } while (option != 0);
    } else {
        cout << "Invalid username or password.\n";
    }
}

// Function to create a new user
void create_new_user(Bank& bank) {
    string username, password, full_name, dob, security_question, security_answer;
    char gender;
    int credit_score;

    cout << "Enter a new username: ";
    cin >> username;

    if (bank.find_user(username)) {
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

    Users newUser(bank.find_user(username) ? bank.find_user(username) + 1 : 1, full_name, gender, username, password, dob, security_question, security_answer, credit_score);
    bank.add_user(newUser);
    cout << "New user created successfully!\n";
}

int main() {
    Bank myBank("Global Bank", 1);

    // Predefined users for testing
    Users user1(1, "John Doe", 'M', "johndoe", "password123", "15/04/1995", "What is your favorite color?", "blue", 750);
    Users user2(2, "User Two", 'M', "a", "b", "01/01/1990", "What is your pet's name?", "buddy", 700);
    Users user3(3, "Charlie Brown", 'M', "x", "y", "23/08/1988", "What is your mother's maiden name?", "smith", 650);
    
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
                login(myBank);
                break;
            case 2:
                create_new_user(myBank);
                break;
            case 3:
                reset_password(myBank);
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
