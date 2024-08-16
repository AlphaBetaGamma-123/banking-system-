#include "Person.h"
#include <iostream>

PersonList createPersonList(int n) {
    PersonList list;
    list.numPeople = n;
    list.people = new Person[n]; 


    for (int i = 0; i < n; ++i) {
        list.people[i].name = "Amey";
        list.people[i].age = 1;
    }

    return list;
}