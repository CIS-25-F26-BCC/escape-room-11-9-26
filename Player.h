//A Player class holds the player's position.
// Its move member function takes a key and the room, and moves the player only if the space in that direction isn't a wall.

#include "Inventory.h"
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

class Room;


class Player {
    private:
        void getItem(Room * r, int x, int y);
        Inventory inventory;
        int x;
        int y; 

    public:
        Player();
        ~Player();
        int getX();
        int getY();
        bool move(char direction, Room * room); 
        std::string printInventory();
};

#endif