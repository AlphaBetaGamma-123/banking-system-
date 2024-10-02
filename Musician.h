#ifndef MUSICIAN_H
#define MUSICIAN_H

#include <string>

using namespace std; 

class Musician {
private:
    string instrument;
    int experience;

public:
    Musician();
    Musician(string s_instrument, int s_experience);

    string get_instrument();
    int get_experience();


    void set_instrument(string new_instrument);
    void set_experience(int new_experience);
};

#endif
