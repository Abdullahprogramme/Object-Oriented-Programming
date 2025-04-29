#ifndef StaminaPotion_hpp
#define StaminaPotion_hpp

#include <iostream>
#include <string>
#include "Potion.hpp"

using namespace std;

class StaminaPotion : public Potion {
    private:
        int staminaRestored; // Amount of stamina restored by the potion

    public:
        StaminaPotion(string name, int staminaRestored); // Constructor to initialize potion name and stamina restored
        ~StaminaPotion(); // Destructor

        int getStaminaRestored(); // Getter for stamina restored
        void setStaminaRestored(int staminaRestored); // Setter for stamina restored
};

#endif // StaminaPotion_hpp