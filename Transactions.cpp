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


    // Displaying info.

    
};