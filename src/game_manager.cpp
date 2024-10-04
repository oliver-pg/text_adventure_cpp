#include "../include/game_manager.h"
#include <iostream>

GameManager::GameManager(std::string playerName) : player(playerName) {}
GameManager::~GameManager() {
    for (auto& room : rooms) {
        delete room.second;
    }
}

void GameManager::initGame() {
    // Create rooms and set descriptions
    rooms[0] = new Room(
        "You are in a small, dimly lit room. There's a door to the north.");
    rooms[1] = new Room("You are in a large hall with a grand chandelier.");

    // Set room exits
    rooms[0]->addExit("north", 1);
    rooms[1]->addExit("south", 0);
}

void GameManager::startGame() {
    std::string command{};
    player.displayStatus();

    while (true) {
        rooms[player.getCurrentRoomId()]->describe();
        std::cout << "> ";
        std::cin >> command;

        if (command == "move") {
            std::string direction{};
            std::cin >> direction;

            int nextRoomId =
                rooms[player.getCurrentRoomId()]->getExit(direction);
            if (nextRoomId != -1) {
                player.move(nextRoomId);
            } else {
                std::cout << "You can't go that way!" << std::endl;
            }
        }
    }
}
