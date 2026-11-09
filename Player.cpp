#include "Player.h"
#include "Room.h"

Player::Player() {
    this->x = 3;
    this->y = 3;
}
Player::~Player() {
    // leave this empty since player currently doesn't allocate any memory that it needs to clean up.
}

int Player::getX() {
    return this->x;
}
int Player::getY() {
    return this->y;
}

// return true if they player moved or false if not
bool Player::move(char direction, Room * room) {


    // take in a direction, check which direciton it is, check if the player can move there in the room
    // then if they can, change the player x and y.

    if(direction == 'w') {
        // (*room).canMove(this->x, this->y - 1);
        if(room->canMove(this->x, this->y - 1)) {
            this->y -= 1;
            return true;
        }
        // check if there is anything blocking us at the position we WOULD go to if we moved in that direction.
    } else if(direction == 'a') {
        if(room->canMove(this->x - 1, this->y)) {
            this->x -= 1;
            return true;
        }
    } else if(direction == 'd') {
        if(room->canMove(this->x + 1, this->y)) {
            this->x += 1;
            return true;
        }
    } else if(direction == 's') {
        if(room->canMove(this->x, this->y + 1)) {
            this->y += 1;
            return true;
        }
    }



    return false; // either an invalid direction or can't move there
}