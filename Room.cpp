#include "Room.h"
#include "Player.h"

#include <iostream>
#include <cstdlib>

using namespace std;


Room::Room(int x, int y, Player * player) {

    this->player = player;

    this->width = x;
    this->height = y;

    this->map = new char*[y];

    for(int outerCounter = 0; outerCounter < y; outerCounter++) {
        this->map[outerCounter] = new char[x];
        for(int innerCounter = 0; innerCounter < x; innerCounter++) {
            if(outerCounter == 0 || outerCounter == (y - 1) || innerCounter == 0 || innerCounter == (x - 1)) {
                this->map[outerCounter][innerCounter] = '#';
            } else if(rand() % 8 == 0 && !(innerCounter == player->getX() && outerCounter == player->getY())) {
                // about one inside space in eight is a wall, but never where the player starts
                this->map[outerCounter][innerCounter] = '#';
            } else {
                this->map[outerCounter][innerCounter] = ' ';
            }
            
        }
    }




 
}
Room::~Room() {
    // release each row, then the array of rows
    for(int outerCounter = 0; outerCounter < height; outerCounter++) {
        delete[] this->map[outerCounter];
    }
    delete[] this->map;
}

bool Room::canMove(int x, int y) {
    if(map[y][x] != '#') {
        return true;
    } else {
        return false;
    }
}

void Room::draw() {
    for(int outerCounter = 0; outerCounter < height; outerCounter++) {
        for(int innerCounter = 0; innerCounter < width; innerCounter++) { // check if the player is on this spot
            if(this->player->getX() == innerCounter && this->player->getY() == outerCounter) {
                cout << '@';
            } else {
                cout << this->map[outerCounter][innerCounter];
            }
        }
        cout << endl;
    }
}