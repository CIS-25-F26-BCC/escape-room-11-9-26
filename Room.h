#include "Item.h"

#ifndef ROOM_H
#define ROOM_H


// The map has a wall of # characters all the way around its edge. More # characters are distributed around the inside of the map, and they act as walls too.

// The @ starts on an open space. After each move, the program draws the whole map again with the @ in its new place.

// The @ never moves onto a #: if the next space is a wall, it stays where it is.

// A Room class holds the map. The map's size isn't known until the program runs, so the Room allocates the map with new and releases it in its destructor.

// The Room can draw itself, with the @ at the player's position.

class Player;


class Room {
    private:
        


        // What does a map look like?
        Player * player;
        int width;
        int height;
        char ** map;

        // 0x576873ABEF -> [#,#,#,#,#,#,#,#,#,#,#,#] the type of this would be: char *
        // 0x75873ABCDF -> [#, , , ,@, ,#, ,#, , ,#]
        // 0x758534BCDA -> [#, , , ,@, ,#, ,#, , ,#]

        // 0x3525243893 -> [0x576873ABEF, 0x75873ABCDF, 0x758534BCDA] char * * 

        // ######################
        // #                    #
        // #              #     #
        // #      #             #
        // #                    #
        // #           #        #
        // #                    #
        // ######################

    public:

        Room(int x, int y, Player * player); // allocate the map
        ~Room(); // deallocate the map
        void draw();
        // char tileAt(int x, int y); might consider this for later
        bool canMove(int x, int y);
        void placeItem(Item * i, int x, int y);
        Item takeItem(int x, int y);
};

#endif