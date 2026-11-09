#include "Inventory.h"
#include "Item.h"
#include <iostream>

bool Inventory::addItem(Item * i) {
    // check how many items we'll have if we add this item
    // then if there's not enough space, we're going to double the size of our array.

    if(this->count >= this->arrayCapacity) {
        // make a new array that's bigger
        Item ** bigger = new Item*[this->arrayCapacity * 2];
        // copy over the things in the old array to the new array
        for(int x = 0; x < this->arrayCapacity; x++) {
            bigger[x] = this->items[x];
        }

        // delete the old array and replace it with the new array
        delete[] items;
        this->items = bigger;

        // set the new capacity
        this->arrayCapacity = this->arrayCapacity * 2;
        
    }

    // actually add the item

    this->items[count] = i;

    this->count += 1;
    
    return true;
}
void Inventory::removeItem(char id) {
    bool deleted = false;
    for(int x; x < count; x++) {
        if(this->items[x]->getId() == id) {
            delete this->items[x];
            this->items[x] = nullptr;
            deleted = true; 
        }

        if(deleted == true) {
            this->items[x - 1] = this->items[x];
            this->items[x] = nullptr;
        }

    }

    if(deleted == true) {
        count -= 1;
    }
}

bool Inventory::hasItem(char id) {
    for(int x; x < count; x++) {
        if(this->items[x]->getId() == id) {
            return true;
        }
    }
    return false;
}
Inventory::Inventory() {
    this->count = 0;
    this->arrayCapacity = 2;
    this->items = new Item*[arrayCapacity];
}
~Inventory::Inventory() {
    for(int x; x < count; x++) {
        delete this->items[x];
    }
    delete[] this->items;
}

std::string Inventory::printInventory() {
    for(int x; x < count; x++) {
        std::cout << this->items[x]->getName() << std::endl;
    }
}