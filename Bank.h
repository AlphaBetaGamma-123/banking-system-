#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>
#include "Users.h"

using namespace std;

class Bank {
private:
    string bank_name;
    int bank_id;
    vector<Users> users_arr;

public:
    Bank(string name, int id);

    void add_user(const Users& user);
    Users* find_user(const string& username);
    void reset_password();
    void login();
    void create_new_user();
};

#endif
