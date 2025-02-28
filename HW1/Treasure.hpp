// This is the treasure class
#ifndef TREASURE_HPP
#define TREASURE_HPP

#include <string>

using namespace std;

class Treasure {
    private:
        string name;
        string description;
        int attack;
        int defense;

    public:
        // Getters and setters
        string getName() const;
        void setName(string name);
        string getDescription() const;
        void setDescription(string description);
        int getAttack();
        void setAttack(int attack);
        int getDefense();
        void setDefense(int defense);

        bool operator==(const Treasure& other) const {
            return name == other.name;
        }
        
        // Constructor
        Treasure();

        // Destructor
        ~Treasure();
};

#endif // TREASURE_HPP
