#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

// Abstract Base class for Accounts
class Accounts {
protected:
    double balance;
    double avail_funds;

public:
    Accounts() : balance(0.0), avail_funds(0.0) {}
    Accounts(double bal, double funds) : balance(bal), avail_funds(funds) {}
    virtual void new_transaction(double amount) = 0; // Abstract function
    virtual void display_account_info() const {
        cout << "Balance: $" << balance << "\n";
    }
    virtual ~Accounts() = default;
};

// TransactionAccount class derived from Accounts
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

// Abstract SavingsAccount class derived from Accounts
class SavingsAccount : public Accounts {
protected:
    double interest_rate;

public:
    SavingsAccount() : Accounts(), interest_rate(0.0) {}
    SavingsAccount(double bal, double funds, double rate) : Accounts(bal, funds), interest_rate(rate) {}

    virtual void add_interest() = 0;
};

// CreditAccount class derived from Accounts
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

// TermSavings class derived from SavingsAccount
class TermSavings : public SavingsAccount {
private:
    int deposit_term;

public:
    TermSavings() : SavingsAccount(), deposit_term(0) {}
    TermSavings(double bal, double funds, double rate, int term)
        : SavingsAccount(bal, funds, rate), deposit_term(term) {}

    void add_interest() override {
        balance += balance * interest_rate;
    }

    void change_term(int new_term) { deposit_term = new_term; }
};

// RewardsCredit class derived from CreditAccount
class RewardsCredit : public CreditAccount {
private:
    int points;
    double points_rate;

public:
    RewardsCredit() : CreditAccount(), points(0), points_rate(0.0) {}
    RewardsCredit(double bal, double funds, double limit, double rate, double pts_rate)
        : CreditAccount(bal, funds, limit, rate), points(0), points_rate(pts_rate) {}

    void add_points(double amount) {
        points += static_cast<int>(amount * points_rate);
    }
    void redeem_points(int pts) {
        if (pts <= points) {
            points -= pts;
            cout << "Redeemed " << pts << " points!\n";
        } else {
            cout << "Not enough points to redeem!\n";
        }
    }
};

// Users class containing user information and accounts
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

    void apply_for_loan() {
        cout << "Your credit score is: " << credit_score << "\n";
        if (credit_score < 600) {
            cout << "Sorry, you are not eligible for a loan.\n";
            return;
        }

        double interest_rate = credit_score >= 800 ? 0.05 : credit_score >= 700 ? 0.1 : 0.15;

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
};

// Bank class to manage users and accounts
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

    int generate_user_id() const {
        return users_arr.size() + 1;
    }

    void reset_password() {
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

    void login() {
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
                cout << "\n1. Apply for Loan\n0. Logout\nEnter option: ";
                cin >> option;
                if (option == 1) user->apply_for_loan();
            } while (option != 0);
        } else {
            cout << "Invalid username or password.\n";
        }
    }

    void create_new_user() {
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

        int new_user_id = generate_user_id();
        Users newUser(new_user_id, full_name, gender, username, password, dob, security_question, security_answer, credit_score);
        add_user(newUser);
        cout << "New user created successfully!\n";
    }
};

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
