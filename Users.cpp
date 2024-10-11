#include <iostream> 
#include <string> 

using namespace std;

class Users {
    protected: 
        // Datamembers. 
        int user_id;
        string full_name;
        char gender;
        string username;
        string password;
        sting dob;
        int num_accounts;
        int accounts[];
    public: 
        // Default constructor. 
        Users(): user_id(0), full_name("No Name"), gender('N'), username("No username"), password("No password"), dob("No DOB"), num_accounts(0), accounts({}) {}
        // Constructor. 
        Users(int id, string name, char g, string user, string pass, string birthdate, int num_acc, int acc)
        : user_id(id), full_name(name), gender(g), username(user), password(pass),
          dob(birthdate), num_accounts(num_acc), accounts(acc) {}

            // string get_assets(){}
   
            // string get_password(){}
            

        // Seeter functions:- Details and login information of the user.
        void change_password (string new_pass) {
            password = new_password; 
        }
        void change_details (string new_name, string new_dob ) {
            full_name = new_name;
            dob = new_dob;
        }

        // Getter functions. 
        int get_user_id() const {return user_id; }
        string get_full_name () const {return full_name; }
        char get_gender () const {return gender; }
        string get_username () const {return username; }
        string get_dob() const {return dob; }
        int get_num_accounts () const {return num_accounts; }
        vector<Accounts*> get_accounts () const {return aaccounts; }

        // Printing. 
        void display_user_info() const {
            cout << "User ID: " << user_id << "\n" ;
            cout << "Full name: " << full_name << "\n" ;
            cout << "Gender: " << gender << "\n" ;
            cout << "DOB: " << dob << "\n" ;
            cout << "Number of accounts: " << num_accounts << "\n" ;
        }
};