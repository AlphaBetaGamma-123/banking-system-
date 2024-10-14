// Abstract class Accounts
#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <iostream>
#include "Transactions.h"

class Accounts {
protected:
    std::string account_name;
    double balance;
    double avail_funds;
    std::vector<Transactions> transaction_log;
public:
    // Default constructor
    Accounts(){

    }

    Accounts(std::string acc_name, double bal, double funds, std::vector<Transactions> trans_log){
        account_name = acc_name;
        balance = bal;
        avail_funds = funds;
        transaction_log = trans_log;
    }

    // Getter methods
    double get_balance() { 
        return balance; 
        }

    double get_avail_funds(){ 
        return avail_funds; 
        }

    Transactions new_transaction(double amount, Accounts dest){
        Transactions t = Transactions(amount, this->get_account_name(), dest.get_account_name());
        balance = balance - amount;
        avail_funds = avail_funds - amount;
        dest.balance = dest.balance + amount;
        dest.avail_funds = dest.avail_funds + amount;
        transaction_log.push_back(t);
        return t;
    };

    std::string get_account_name(){
        return account_name;
    }


    virtual ~Accounts() = default;

};

#endif