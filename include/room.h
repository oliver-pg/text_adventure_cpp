#ifndef ROOM_H
#define ROOM_H

#include "interactable.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

// The Room class - each room is like a moment in life.
// It holds its own challenges, its own opportunities, and ways to move forward.
class Room {
    std::string description{}; // A simple description to reflect what this room
                               // feels like.
    std::map<std::string, int>
        exits{}; // The paths out of the room - where you can go next.
    std::vector<Interactable*>
        interactables{}; // Objects in the room you can engage with.

  public:
    // The room starts with a description - a small detail about where you are,
    // right now.
    Room(std::string desc);

    // Adds an exit - a direction to move forward, and the next room it leads
    // to. Think of it as laying out the map of your journey.
    void addExit(const std::string& direction, int roomId);

    // Retrieves the next room based on the direction you choose.
    // If the path doesn't exist, it simply returns -1, like hitting a dead-end
    // in life.
    int getExit(const std::string& direction) const;

    // Describes the room to the player - a simple moment of awareness, taking
    // in your surroundings.
    void describe() const;

    // Adds something you can interact with in the room.
    // Like placing a lever or a door in the room, something to engage with.
    void addInteractable(Interactable* obj) { interactables.push_back(obj); }

    // Allows the player to interact with everything in the room.
    // Engage with the world and see what actions come from it.

    void interactWithObject(const std::string& objectName) const {
        // Each object in the room waits for attention, an invitation to act.
        for (const auto& obj : interactables) {
            // Checking if it's the lever - the player might be ready to engage.
            if (Lever* lever = dynamic_cast<Lever*>(obj)) {
                if (objectName == "lever") {
                    lever->interact();
                    return; // Once the lever is pulled, the interaction is
                            // complete.
                }
                // Checking for a door - maybe it's time to open the way
                // forward.
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
    };

#endif // ROOM_H
