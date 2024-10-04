#include "../include/player.h"
#include <iostream>

Player::Player(std::string playerName) : name(playerName), currentRoomId(0) {}

void Player::move(int newRoomId) {
    currentRoomId = newRoomId;
    std::cout << name << " moved to room " << newRoomId << std::endl;
}

void Player::addItem(const std::string& item) {
    inventory.push_back(item);
    std::cout << item << " added to inventory." << std::endl;
}

int Player::getCurrentRoomId() const { return currentRoomId; }

void Player::displayStatus() const {
    std::cout << "Player: " << name << "\nCurrent Room: " << currentRoomId
              << std::endl;
    std::cout << "Inventory: ";
    for (const auto& item : inventory) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
