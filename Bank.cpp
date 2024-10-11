#include <iostream> 
#include <string> 

using namespace std;

class Bank {
    private:
        // Datamembers. 
        string bank_name;
        int bank_id;
        vector<Accounts*> account_arr;  // Holds pointers to Accounts objects (polymorphism). 
        vector<Users> users_arr;

    public:
        // Default constructor
        Bank() : bank_name("Unnamed Bank"), bank_id(0) {}

        // Parameterized constructor
        Bank(string name, int id, vector<Accounts*> acc_arr, vector<Users> users)
            : bank_name(name), bank_id(id), accounts_arr(acc_arr), users_arr(users) {}

        // Methods to add and remove accounts. 
        void add_account(Accounts* account) {accounts_arr.push_back(account); }
        void del_account() {//Placeholder
        }

        void add_user(Users* user) { users_arr.push_back(user); }
        void del_user(int user_id) {}  // Placeholder


        // Getter functions. 
        string get_bank_name() { return bank_name; }
        int get_bank_id() { return bank_id; }
        vector<Accounts*> get_accounts_arr() { return accounts_arr; }
        vector<Users> get_users_arr() { return users_arr; }

        // Displaying the info.
        void display_user_info () {
            cout << "Bank Name: " << bank_name << "\n"; 
            cout << "Bank ID: " << bank_id << "\n";
            cout << "Number of accounts: " << account_arr.size() << "\n";
            cout << "Number of users: " << users_arr.size() << "\n";
        }
};