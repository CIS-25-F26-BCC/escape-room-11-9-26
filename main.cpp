#include <iostream>
#include "Player.h"
#include "Room.h"

using namespace std;

int main() {
    // TODO: When the program starts, it asks the user how big the map should be: a number of rows and a number of columns.
    
    // w moves up, a left, s down, and d right.

    Player player;
    Room room(20,10, &player);
    

    bool isRunning = true;

    while(isRunning) { // main game loop

        room.draw();

        char input;
        cout << endl << endl << "Please use the wasd keys to move or press q to quit: ";
        cin >> input;

        if(input == 'q') {
            isRunning = false;
        } else {
            player.move(input, &room);
        }

    }
    
    return 0;
}