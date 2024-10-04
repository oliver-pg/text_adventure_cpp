// Player implementation: Here we define the actions that the player can take
// Moving, picking up items, and reflecting on their journey

#include "../include/player.h"
#include <iostream>

// Constructor: We name the player and set their starting room
Player::Player(std::string playerName) : name(playerName), currentRoomId(0) {}

// Moves the player to a new room
void Player::move(int newRoomId) {
    currentRoomId = newRoomId;
    std::cout << name << " moved to room " << newRoomId
              << std::endl; // Reflecting the player's movement
}

// Adds an item to the player's inventory, a simple action of gathering
void Player::addItem(const std::string& item) {
    inventory.push_back(item);
    std::cout << item << " added to inventory."
              << std::endl; // Acknowledging the gain of a new possession
}

// Displays the player's current status: where they are and what they hold
void Player::displayStatus() const {
    std::cout << "Player: " << name << "\nCurrent Room: " << currentRoomId
              << std::endl;
    std::cout << "Inventory: ";
    for (const auto& item : inventory) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// Returns the ID of the room the player is currently in
int Player::getCurrentRoomId() const {
    return currentRoomId; // Always knowing where you are in the present
}
