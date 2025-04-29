#ifndef HealthPotion_hpp
#define HealthPotion_hpp

#include <string>
#include "Potion.hpp"

using namespace std;

class HealthPotion : public Potion {
    private:
        int healthRestored; // Amount of health restored by the potion

    public:
        HealthPotion(string name, int healthRestored); // Constructor to initialize potion name and health restored
        ~HealthPotion(); // Destructor

        int getHealthRestored(); // Getter for health restored
        void setHealthRestored(int healthRestored); // Setter for health restored
};

#endif // HealthPotion_hpp