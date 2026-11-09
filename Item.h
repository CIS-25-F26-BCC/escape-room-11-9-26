#include <iostream>

#ifndef ITEM_H
#define ITEM_H

class Item {
    private:
        char id;
        std::string name;
    public:
        static std::string getNameFromId(char id);
        Item(char id, std::string name);
        char getId();
        std::string getName();
};

#endif