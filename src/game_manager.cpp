#include "../include/game_manager.h"
#include "../include/door.h"
#include "../include/lever.h"
#include <sstream>

// Constructor - this is where we gently set the stage for our player's journey.
// In life, as in code, everything starts with intention, and here we name our
// player, preparing them to explore the world.
GameManager::GameManager(std::string playerName) : player(playerName) {
    // There may be times when additional preparation is necessary, but for now,
    // we breathe and trust the simplicity of this setup.
}

// Destructor - when the time comes to part ways with our game, we must clear up
// what we’ve created. Just like in life, we practice letting go, releasing
// memory we've held onto, to leave things in balance.
GameManager::~GameManager() {
    // We carefully release each room we created, acknowledging the role it
    // played in the journey. With every delete, we return memory to where it
    // came from, knowing that nothing truly lasts forever.
    for (auto& room : rooms) {
        delete room.second;
    }
}

// Initializes the game, setting up the rooms, exits, and interactable objects.
// This is like building the world before the player starts their journey.
void GameManager::initGame() {
    // The first room - a small, dimly lit room with a lever.
    Room* room0 = new Room("You are in a small, dimly lit room with a lever.");
    Door* door0 =
        new Door(); // A locked door stands here, waiting to be unlocked.
    Lever* lever0 = new Lever(door0); // This lever is connected to the door.
    room0->addInteractable(lever0);
    room0->addInteractable(door0);
    room0->addExit(
        "north",
        1); // The path ahead leads north, but the door must be opened first.

    // The second room - a large hall.
    Room* room1 =
        new Room("You are in a large hall with a locked door to the north.");
    room1->addExit("south", 0); // A way back, through the locked door.

    // We add the rooms to the game world.
    rooms[0] = room0;
    rooms[1] = room1;
}

// The game loop - this is where the player begins interacting with the world.
// The loop runs until the player decides to end the game.
void GameManager::startGame() {
    player.displayStatus();
    // The main loop - the player navigates the world, one moment at a time.
    while (true) {
        rooms[player.getCurrentRoomId()]
            ->describe();  // Describe the player's surroundings.
        std::cout << "> "; // A quiet invitation for the player to act.

        std::string inputLine{};
        std::getline(std::cin, inputLine); // Read the entire line of input

        std::istringstream inputStream(inputLine);
        std::string command{};
        inputStream >> command;

        if (command == "move") {
            std::string direction{};
            inputStream >> direction;

            // The player chooses a direction to move in the current room.
            if (!direction.empty()) {
                int nextRoomId =
                    rooms[player.getCurrentRoomId()]->getExit(direction);

                // Check if there is an exit in the specified direction.
                if (nextRoomId != -1) {
                    // Iterate through the interactables in the current room to
                    // find a Door
                    bool doorLocked = false;
                    for (Interactable* interactable :
                         rooms[player.getCurrentRoomId()]->getInteractables()) {
                        Door* door = dynamic_cast<Door*>(interactable);
                        if (door && door->isLockedState()) {
                            doorLocked = true;
                            break;
                        }
                    }
                    // If the door is locked, remind the player
                    if (doorLocked) {
                        std::cout << "The door is locked. You can't go through."
                                  << std::endl;
                    } else {
                        player.move(nextRoomId); // Movement, the simplest form
                                                 // of progress.
                    }
                } else {
                    std::cout << "You can't go that way!" << std::endl;
                }
            } else {
                std::cout << "Please specify a direction." << std::endl;
            }
        } else if (command == "interact") {
            std::string object{};
            inputStream >> object;

            // The player reaches out to interact with an object in the room.
            if (!object.empty()) {
                rooms[player.getCurrentRoomId()]->interactWithObject(
                    object); // Interact with something specific.
            } else {
                std::cout << "Please specify an object to interact with."
                          << std::endl;
            }
        } else {
            std::cout << "Unknown command."
                      << std::endl; // Remind the player to use known commands.
        }
    }
}
