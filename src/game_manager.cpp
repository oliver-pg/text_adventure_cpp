// GameManager implementation: This is where we breathe life into the game
// Each function here guides the player through their journey

#include "../include/game_manager.h"
#include <iostream>

// Constructor: We set the player's name and prepare the adventure
GameManager::GameManager(std::string playerName) : player(playerName) {}

// Destructor: Time to clean up the rooms and close the chapter
GameManager::~GameManager() {
    for (auto& room : rooms) {
        delete room.second; // Releasing all the memory we used, letting go of
                            // attachments
    }
}

// Initializes the world by setting up the rooms and exits
void GameManager::initGame() {
    // Create rooms and set descriptions, preparing the environment
    rooms[0] = new Room(
        "You are in a small, dimly lit room. There's a door to the north.");
    rooms[1] = new Room("You are in a large hall with a grand chandelier.");

    // Set room exits, connecting the dots of the journey
    rooms[0]->addExit("north", 1);
    rooms[1]->addExit("south", 0);
}

// The core game loop: Where the player interacts with the world and makes
// decisions
void GameManager::startGame() {
    std::string command{};  // The player's chosen action
    player.displayStatus(); // A quick reflection on where the player stands

    while (true) {
        rooms[player.getCurrentRoomId()]
            ->describe(); // Describe the current room, a moment of mindfulness
        std::cout << "> ";
        std::cin >> command; // Take input from the player, the next move

        if (command == "move") {
            std::string direction{};
            std::cin >> direction;

            // Move the player if there's an exit in the given direction
            int nextRoomId =
                rooms[player.getCurrentRoomId()]->getExit(direction);
            if (nextRoomId != -1) {
                player.move(nextRoomId); // A step forward on the path
            } else {
                std::cout << "You can't go that way!" << std::endl;
            }
        }
    }
}
