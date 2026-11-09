#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Room.h"
#include "Item.h"

using namespace std;

int main() {
    // w moves up, a left, s down, and d right.

    srand(time(0)); // different inside walls each time the game runs

    // When the program starts, it asks the user how big the map should be: a number of rows and a number of columns.
    int rows = 0;
    int columns = 0;
    while(rows < 3 || columns < 3) {
        cout << "How many rows? ";
        cin >> rows;
        cout << "How many columns? ";
        cin >> columns;
        if(rows < 3 || columns < 3) {
            cout << "The map needs at least 3 rows and 3 columns." << endl;
        }
    }

    Player player;
    Room room(columns, rows, &player);

    Item key('k', "key");
    room.placeItem(&key, 2,2);

    bool isRunning = true;

    while(isRunning) { // main game loop

        room.draw();
        cout << player.printInventory();

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