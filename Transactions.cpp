#include <iostream> 
#include <string> 

using namespace std;

class Transactions {
protected:
    // Datamembers. 
    int origin_acc;
    int dest_acc;
    int id;
    int time;

public:
    // Default constructor
    Transactions() : origin_acc(0), dest_acc(0), id(0), time(0) {}

    // Parameterized constructor
    Transactions(int o_acc, int d_acc, int trans_id, int trans_time) : origin_acc(o_acc), dest_acc(d_acc), id(trans_id), time(trans_time) {}

     // Getter methods
    int get_origin_acc() { return origin_acc; }
    int get_dest_acc() { return dest_acc; }
    int get_id() { return id; }
    int get_time() { return time; }

    // Displaying info.
    void display_transaction_info() {
        cout << "Account From: " << origin_acc << "\n";
        cout << "Account To: " << dest_acc << "\n";
        cout << "Account ID: " << id << "\n";
        cout << "Time: " << ctime(&time);

    }
    
};