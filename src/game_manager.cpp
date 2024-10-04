#include "../include/game_manager.h"
#include "../include/door.h"
#include "../include/lever.h"

// Initializes the game, setting up the rooms, exits, and interactable objects.
// This is like building the world before the player starts their journey.
void GameManager::initGame() {
    // Create two rooms
    Room* room1 = new Room("You are in a small, dimly lit room with a lever.");
    Room* room2 =
        new Room("You are in a large hall with a locked door to the north.");

    // Add exits - room 1 leads north to room 2, and room 2 leads back south to
    // room 1.
    room1->addExit("north", 1);
    room2->addExit("south", 0);

    // Place a lever in room 1 - something to interact with.
    Lever* lever = new Lever();
    room1->addInteractable(lever);

    // Place a door in room 2 - it's locked, but the lever might help...
    Door* door = new Door();
    room2->addInteractable(door);

    // Assign the rooms to the game manager's room map.
    rooms[0] = room1;
    rooms[1] = room2;
}

// The game loop - this is where the player begins interacting with the world.
// The loop runs until the player decides to end the game.
void GameManager::startGame() {
    std::string command; // A place to store the player's input.

    // Show the player's current status (where they are, inventory, etc.)
    player.displayStatus();

    // The main loop where the player interacts with the game world.
    while (true) {
        // Describe the current room to the player - they need to understand
        // their environment.
        rooms[player.getCurrentRoomId()]->describe();
        std::cout << "> "; // Command prompt
        std::cin >> command;

        if (command == "move") {
            std::string direction; // Which way the player wants to go
            std::cin >> direction;

            // Check if the player can move in the chosen direction
            int nextRoomId =
                rooms[player.getCurrentRoomId()]->getExit(direction);
            if (nextRoomId != -1) {
                player.move(nextRoomId); // Move the player if the exit is valid
            } else {
                std::cout << "You can't go that way!" << std::endl;
            }
        } else if (command == "interact") {
            // If the player chooses to interact, engage with the objects in the
            // room.
            rooms[player.getCurrentRoomId()]->interactWithObjects();
        }
    }
}
