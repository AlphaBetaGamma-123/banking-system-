#include <iostream>
#include "Person.h"

using namespace std;


Person* createPersonArray(int n);

int main() {

    int n = 5;

 
    Person* personArray = createPersonArray(n);

    
    for (int i = 0; i < n; ++i) {
        cout << "Person " << i + 1 << ": Name - " << personArray[i].name << ", Age - " << personArray[i].age <<  endl;
    }

    delete[] personArray;

    return 0;
}