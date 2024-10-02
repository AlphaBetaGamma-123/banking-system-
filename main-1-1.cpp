#include <iostream>
#include "Musician.h"

using namespace std; 

int main() {
    Musician m1;
    cout << "Default instrument: " << m1.get_instrument() << ", Default experience: " << m1.get_experience() << endl;

    Musician m2("guitar", 5);
    cout << "Instrument: " << m2.get_instrument() << ", Experience: " << m2.get_experience() << endl;

    return 0;
}
