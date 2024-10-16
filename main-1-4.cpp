#include "Person.h"
#include <iostream>
using namespace std;

int main() {

    int num = 3; 

    PersonList originalList = createPersonList(num);
    PersonList copiedList = shallowCopyPersonList(originalList);
    // PersonList copiedList = shallowCopyPersonList(originalList); 



    cout << "Original List:" << endl;
    for (int i = 0; i < originalList.numPeople; ++i) {
        cout <<   "Person " << i + 1 << ": Name = "   << originalList.people[i].name << ", Age = " << originalList.people[i].age << endl;
    }

    cout << "Copied List:" << endl;
    for (int i = 0; i < copiedList.numPeople; ++i) {
        cout<< "Person " << i + 1 << ": Name = " <<  copiedList.people[i].name  << ", Age = " << copiedList.people[i].age << endl;
    }

    delete[] originalList.people;





    return 0;
}
