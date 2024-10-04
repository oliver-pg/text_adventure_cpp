// Room implementation: Defines what the player sees and how they navigate
// Each room is like a chapter of a story, interconnected with the others

#include "../include/room.h"
#include <iostream>

// Constructor: Initializes the room with a description
Room::Room(std::string desc) : description(desc) {}

// Adds an exit to another room, creating a path in a given direction
void Room::addExit(const std::string& direction, int roomId) {
    exits[direction] = roomId;
}

// Retrieves the room ID for the next room when the player takes a direction
int Room::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second; // Returning the next step on the journey
    }
    return -1; // If no exit exists in that direction, a moment of pause
}

// Provides the player with a description of the room
void Room::describe() const {
    std::cout << description << std::endl; // Sharing the moment's experience,
                                           // the atmosphere of the room
}
