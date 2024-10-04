// Room class: Represents the environment, each room has its own feel and
// purpose In life, we pass through many rooms, each with its own lessons

#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <string>

// Room class manages the description, exits, and interactables in each space
class Room {
    std::string description{}; // A short description to paint a picture of
                               // where the player is
    std::map<std::string, int>
        exits{}; // Directions mapped to the next rooms, paths of the journey

  public:
    Room(std::string desc); // Constructor to set the initial feel of the room
    void addExit(const std::string& direction,
                 int roomId); // Adds a connection to another room in a specific
                              // direction
    int getExit(const std::string& direction)
        const; // Retrieves the next room ID when a direction is taken
    void describe() const; // Provides the player with the current room
                           // description, a moment of stillness
};

#endif // ROOM_H
