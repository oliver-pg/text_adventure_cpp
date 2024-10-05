// Player implementation: Here we define the actions that the player can take
// Moving, picking up items, and reflecting on their journey

#include "../include/player.h"
#include <algorithm>
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
void Player::addItem(const Item& item) {
    inventory.push_back(item);
    std::cout << item.getName() << " added to inventory."
              << std::endl; // Acknowledging the gain of a new possession
}

// Displays the player's current status: where they are and what they hold
void Player::displayStatus() const {
    std::cout << "Player: " << name << "\nCurrent Room: " << currentRoomId
              << std::endl;
    std::cout << "Inventory: ";
    for (const auto& item : inventory) {
        std::cout << item.getName() << " ";
    }
    std::cout << std::endl;
}

// Returns the ID of the room the player is currently in
int Player::getCurrentRoomId() const {
    return currentRoomId; // Always knowing where you are in the present
}

void Player::removeItem(const std::string& itemName) {
    auto it = std::remove_if(
        inventory.begin(), inventory.end(),
        [&itemName](const Item& item) { return item.getName() == itemName; });
    if (it != inventory.end()) {
        inventory.erase(it);
        std::cout << "You have removed " << itemName << " from your inventory."
                  << std::endl;
    } else {
        std::cout << "You don't have " << itemName << "." << std::endl;
    }
}

void Player::listInventory() const {
    if (inventory.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
    } else {
        std::cout << "Your inventory contains:" << std::endl;
        for (const auto& item : inventory) {
            std::cout << "- " << item.getName() << ": " << item.getDescription()
                      << std::endl;
        }
    }
}

bool Player::hasItem(const std::string& itemName) const {
    return std::any_of(
        inventory.begin(), inventory.end(),
        [&itemName](const Item& item) { return item.getName() == itemName; });
}

void Player::useItem(const std::string& itemName) {
    auto it = std::find_if(
        inventory.begin(), inventory.end(),
        [&itemName](const Item& item) { return item.getName() == itemName; });
    if (it != inventory.end()) {
        it->use();
    } else {
        std::cout << "You don't have " << itemName << " in your inventory."
                  << std::endl;
    }
}
