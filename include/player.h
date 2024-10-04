// Player class: Represents the adventurer, the one taking on the challenges
// We are all the players of our own stories, navigating through life's rooms

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

// Player class is responsible for managing the player's state
class Player {
    std::string name;  // The name of the player, unique to each journey
    int currentRoomId; // Tracks the room the player is currently in
    std::vector<std::string>
        inventory; // A collection of items the player gathers along the way

  public:
    Player(std::string playerName); // Constructor to name our adventurer and
                                    // set their starting point
    void move(int newRoomId);       // Moves the player from one room to another
    void addItem(const std::string& item); // Adds an item to the player's
                                           // inventory, simple treasures
    void
    displayStatus() const; // Shows the player's current status and possessions

    int getCurrentRoomId() const; // Retrieves the ID of the room the player is
                                  // in, staying aware of the present moment
};

#endif // PLAYER_H
