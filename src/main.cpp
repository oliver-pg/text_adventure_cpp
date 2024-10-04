// Main function: The entry point of the adventure
// Here we create the GameManager and let the player begin their journey

#include "../include/game_manager.h"

int main() {
    GameManager game(
        "Adventurer"); // We start by giving the player a name, a new identity
    game.initGame();   // Initialize the world, setting up rooms and connections
    game.startGame();  // Start the main loop, where all actions unfold

    return 0; // End of the program, the adventure has concluded, for now
}
