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

    Transactions new_transaction(double amount, Accounts &dest){
        if(amount >0){

            if (balance >= amount) {
            //Transactions t = Transactions(amount, this->get_account_name(), dest.get_account_name());
            balance = balance - amount;
            avail_funds = avail_funds - amount;
            Transactions t = dest.new_transaction(-amount, dest);
            transaction_log.push_back(t);
            return t;

            } else {
                cout << "\nTransaction exceeds account balance!";
                return Transactions();
            }
        }else{
            balance = balance - amount;
            avail_funds = avail_funds - amount;
            Transactions t = Transactions(-amount, this->get_account_name(), dest.get_account_name());
            transaction_log.push_back(t);
            std::cout << balance;
            return t;
        }
    };

    std::string get_account_name(){
        return account_name;
    }

    std::string write_account(){
        
    }


    virtual ~Accounts() = default;

};

#endif