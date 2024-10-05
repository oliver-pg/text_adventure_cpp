// GameManager class: This is the heart of the game, keeping track of everything
// It's all about balance—managing the player, rooms, and the flow of the game
// with ease

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "player.h"
#include "room.h"
#include <map>

// GameManager class handles the player's journey and the world (rooms)
// It's the quiet guide behind the scenes
class GameManager {
    Player player; // Our adventurer, the main protagonist
    std::map<int, Room*>
        rooms{}; // A collection of all rooms, connected in ways unknown

  public:
    GameManager(
        std::string playerName); // Constructor, the beginning of the adventure
    ~GameManager(); // Destructor, when it's time to let go and clean up

    void initGame();  // Set everything in motion, initializing the world
    void startGame(); // Where the magic happens, the core game loop
};

#endif // GAME_MANAGER_H
