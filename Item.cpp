#include "Item.h"
#include <iostream>

Item::Item(char id, std::string name) {
    this->id = id;
    this->name = name;
}

char Item::getId() {
    return this->id;
}

std::string Item::getName() {
    return this->name;
}

std::string Item::getNameFromId(char id) {
    if(id == 'k') {
        return "key";
    } else {
        return "N/A";
    }
}