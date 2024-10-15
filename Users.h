#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <string>
#include <memory>
#include "Accounts.h"

using namespace std;

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
    shared_ptr<Accounts> account;

public:
    Users(int id, string name, char g, string user, string pass, string birthdate, string sec_question, string sec_answer, int score, shared_ptr<Accounts> acc);

    string get_username() const;
    string get_password() const;
    string get_security_question() const;
    string get_security_answer() const;
    int get_credit_score() const;

    void change_password(string new_pass);
    void display_user_info() const;
    void deposit(double amount);
    void withdraw(double amount);
    void transfer_funds(Users &receiver, double amount);
};

#endif
