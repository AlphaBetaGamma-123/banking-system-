#ifndef ORCHESTRA_h
#define ORCHESTRA_h

#include "Musician.h"

using namespace std; 

class Orchestra {

        private: 
            Musician* members; 
            int current_size ; 
            int max_size;  

        public:
            // Default constructor. 
            Orchestra(); 

            // Parameter constructor. 
            Orchestra(int size);

            // Get function. 
            int get_current_number_of_members(); 

            // returns true if any musician in the orchestra plays the specified instrument
            // otherwise returns false
            bool has_instrument(string instrument); 

            Musician* get_members();        // returns the array of members of the orchestra

            // returns true and adds new musician to the orchestra if the orchestra is not full
            // otherwise returns false
            bool add_musician(Musician new_musician);

            ~Orchestra();


};

#endif // ORCHESTRA_H