// The Inventory can add an item, remove an item by its id, and say whether it holds one.
// It releases its array in its destructor, and it's never copied: pass it by reference.

#include "Item.h"
#include <iostream>

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
    private:
        int count;
        int arrayCapacity;
        Item ** items;

        // 0x5676 -> [0x3232, 0x2523, 0x4633]

    public:
        bool addItem(Item * i);
        void removeItem(char id);
        bool hasItem(char id);
        Inventory();
        ~Inventory();
        std::string printInventory();
};

#endif