#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream fin;

    fin.open("data.txt");

    if(!fin) {
        cerr << "Error in opening the file" << endl;
        return 1; // if this is main
    }

    static const char* const FILENAME_PEOPLE = "people.txt";

    
    ofstream fout;
    fout.open(FILENAME_PEOPLE); // be sure that the argument is a c string
    if (!fout) {
        cerr << "Error in opening the output file" << endl;

        // again only if this is main, chain return codes or throw an exception otherwise
        return 1; 
    }

}