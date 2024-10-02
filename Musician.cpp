#include "Musician.h"
using namespace std; 

// Default constructor. 
Musician::Musician() {
    instrument = " ";
    experience = 0; 
}

// Constructor. 
Musician::Musician(string s_instrument, int s_experience) {
    instrument = s_instrument;
    experience = s_experience;
}

// Get functions. 
string Musician::get_instrument(){return instrument; }
int Musician::get_experience(){return experience; }

// Set functions. 
void Musician::set_instrument(string new_instrument){instrument = new_instrument;}
void Musician::set_experience(int new_experience) {experience = new_experience;}
