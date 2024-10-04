#include "../include/room.h"
#include <iostream>

// The room is created with a description. Each room, like each moment in life,
// starts with a story.
Room::Room(std::string desc) : description(desc) {}

// Adding an exit gives you a path forward - a chance to move from this room to
// the next.
void Room::addExit(const std::string& direction, int roomId) {
    exits[direction] = roomId;
}

// Retrieves the room ID in a given direction. If there's no exit, it's like
// finding no clear way out.
int Room::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second;
    }
    return -1; // No exit in this direction.
}

// Describes the room to the player, helping them understand where they are,
// right now.
void Room::describe() const { std::cout << description << std::endl; }
