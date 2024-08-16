#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    std::string name;
    int age;
};

struct PersonList {
    Person* people;
    int numPeople;
};


PersonList createPersonList(int n);
PersonList deepCopyPersonList(PersonList pl);
PersonList shallowCopyPersonList(PersonList pl);

#endif // PERSON_H