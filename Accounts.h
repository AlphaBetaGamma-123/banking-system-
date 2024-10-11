// Abstract class Accounts
#include <iostream>

class Accounts {
protected:
    double balance;
    double avail_funds;

public:
    // Default constructor
    Accounts(){
        balance = 0;
        avail_funds = 0;
    }

    // Abstract method for transactions (to be defined in derived classes)
    void new_transaction(){

    }

    // Getter methods
    double get_balance() { 
        return balance; 
        }

    double get_avail_funds(){ 
        return avail_funds; 
        }

};