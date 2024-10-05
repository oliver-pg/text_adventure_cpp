#ifndef ROOM_H
#define ROOM_H

#include "door.h"
#include "interactable.h"
#include "item.h"
#include "lever.h"
#include "player.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

// The Room class - each room is like a moment in life.
// It holds its own challenges, its own opportunities, and ways to move forward.
class Room {
  private:
    std::string description{}; // A simple description to reflect what this room
                               // feels like.
    std::map<std::string, int>
        exits{}; // The paths out of the room - where you can go next.

    std::vector<Interactable*>
        interactables{}; // Objects in the room you can engage with.

    std::vector<Item> itemsInRoom{};

  public:
    // The room starts with a description - a small detail about where you are,
    // right now.
    Room(std::string desc);

    void movePlayer(const std::string& direction, Player& player);

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

    const std::vector<Interactable*>& getInteractables() const {
        return interactables;
    }

    // Allows the player to interact with everything in the room.
    // Engage with the world and see what actions come from it.
    void interactWithObject(const std::string& objectName) const;

    void addItem(const Item& item);
    void listItems() const;
    bool pickupItem(const std::string& itemName, Player& player);
};

#endif // ROOM_H
