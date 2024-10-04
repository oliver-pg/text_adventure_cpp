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

// Allows the player to interact with everything in the room.
// Engage with the world and see what actions come from it.
void Room::interactWithObject(const std::string& objectName) const {
    Door* door = nullptr;
    // Find the door in the room
    for (const auto& obj : interactables) {
        if (Door* d = dynamic_cast<Door*>(obj)) {
            door = d;
            break;
        }
    }

    // Each object in the room waits for attention, an invitation to act.
    for (const auto& obj : interactables) {
        // Checking if it's the lever - the player might be ready to engage.
        if (Lever* lever = dynamic_cast<Lever*>(obj)) {
            if (objectName == "lever") {
                lever->interact(door); // Pass the door to the lever's interact
                                       // function
                return;
            }
            // Checking for a door - maybe it's time to open the way forward.
        } else if (Door* door = dynamic_cast<Door*>(obj)) {
            if (objectName == "door") {
                door->interact();
                return;
            }
        }
    }
    // If the object isn't found, we remind the player to look closer.
    std::cout << "There's nothing like that here to interact with."
              << std::endl;
}
