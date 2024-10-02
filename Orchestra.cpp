#include <iostream>
#include "Orchestra.h"

using namespace std; 

#include <string>

// Default Constructor. 
Orchestra:: Orchestra() {
    members = nullptr;
    current_size = 0;
    max_size = 0;
}

// Parameterized constructor. 
Orchestra:: Orchestra(int size) {

    current_size = 0;
    max_size = size; 
    members = new Musician[size]; 
}

// Get function. 
// Get function
int Orchestra::get_current_number_of_members() {
    return current_size;
}
bool Orchestra::has_instrument(string instrument) {
    for (int i = 0; i< current_size; i++) {
        if (members[i].get_instrument () == instrument) {
            return true;
        }
    return false;
    }
}

// Returns pointer to members
Musician* Orchestra::get_members() {
    return members; 
}

bool Orchestra::add_musician(Musician new_musician){
    if (current_size < max_size) {
        members[current_size] = new_musician; 
        current_size++;  
        return true; 
    } 
    return false;   
}

// Destructor. 
Orchestra::~Orchestra(){
    delete [] members; 
}