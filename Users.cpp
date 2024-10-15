#include "Users.h"

Users::Users(int id, string name, char g, string user, string pass, string birthdate, string sec_question, string sec_answer, int score, shared_ptr<Accounts> acc)
    : user_id(id), full_name(name), gender(g), username(user), password(pass), dob(birthdate), security_question(sec_question), security_answer(sec_answer), credit_score(score), account(acc) {}

string Users::get_username() const { return username; }
string Users::get_password() const { return password; }
string Users::get_security_question() const { return security_question; }
string Users::get_security_answer() const { return security_answer; }
int Users::get_credit_score() const { return credit_score; }

void Users::change_password(string new_pass) { password = new_pass; }

void Users::display_user_info() const {
    cout << "User ID: " << user_id << "\nFull Name: " << full_name << "\n";
    cout << "DOB: " << dob << "\n";
    account->display_account_info();
}

void Users::deposit(double amount) {
    account->new_transaction(amount);
    cout << "Deposit successful.\n";
}

void Users::withdraw(double amount) {
    if (account->get_balance() >= amount) {
        account->new_transaction(-amount);
        cout << "Withdraw successful.\n";
    } else {
        cout << "Insufficient funds.\n";
    }
}

void Users::transfer_funds(Users &receiver, double amount) {
    if (account->get_balance() >= amount) {
        account->set_balance(account->get_balance() - amount);
        receiver.account->set_balance(receiver.account->get_balance() + amount);
        cout << "Transfer successful.\n";
    } else {
        cout << "Insufficient funds for transfer.\n";
    }
}
