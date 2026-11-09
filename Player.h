//A Player class holds the player's position.
// Its move member function takes a key and the room, and moves the player only if the space in that direction isn't a wall.

#ifndef PLAYER_H
#define PLAYER_H

class Room;


class Player {
    private:
        int x;
        int y; 

    public:
        Player();
        ~Player();
        int getX();
        int getY();
        bool move(char direction, Room * room);
};

#endif