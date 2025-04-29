#ifndef Gun_hpp
#define Gun_hpp

#include <string>
#include "Weapon.hpp"

using namespace std;

class Gun : public Weapon {
    public:
        Gun(string name, int damage, int durability); // Constructor to initialize gun attributes
        ~Gun(); // Destructor
};

#endif // Gun_hpp