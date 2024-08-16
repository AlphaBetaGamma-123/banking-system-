
#include "Person.h"
#include <iostream>

PersonList deepCopyPersonList(PersonList pl) {
    PersonList newList;
    newList.numPeople = pl.numPeople;
    newList.people = new Person[pl.numPeople]; 

    
    for (int i = 0; i < pl.numPeople; ++i) {
        newList.people[i].name = pl.people[i].name;
        newList.people[i].age = pl.people[i].age;
    }

    return newList;
}
