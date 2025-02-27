// This is the Inventory class

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Treasure.hpp"
#include <string>
using namespace std;


class Inventory {
    private:
        Treasure* arr;
        int size;
        int capacity;
        string name;
        int attack;
        int defense;

        void Resize();

    public:
        // Constructor
        Inventory(int size, int capacity);
        
        // Destructor
        ~Inventory();

        // Methods
        void Add(Treasure item);
        void Remove(Treasure item);
        void Print();

        bool operator==(const Treasure& other) const;
};

#endif // INVENTORY_HPP