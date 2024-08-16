#include "Person.h"
using namespace std;

PersonList shallowCopyPersonList(PersonList pl) {

    PersonList newList;


    newList.numPeople = pl.numPeople;
    newList.people = pl.people; 

    
    return newList;
}