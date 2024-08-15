#include "Person.h"

Person* createPersonArray(int n) 
{
    Person* array = new Person[n];
    for (int i = 0; i < n; ++i) {
        array[i].name = "John Doe";
        array[i].age = 0;
    }


    return array;
}