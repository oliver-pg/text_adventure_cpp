#include "../include/game_manager.h"
#include "../include/door.h"
#include "../include/lever.h"

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
    // Create two rooms
    Room* room1 = new Room("You are in a small, dimly lit room with a lever.");
    Room* room2 =
        new Room("You are in a large hall with a locked door to the north.");

    // Add exits - room 1 leads north to room 2, and room 2 leads back south to
    // room 1.
    room1->addExit("north", 1);
    room2->addExit("south", 0);

    // Place a door in room 2
    Door* door = new Door();
    room2->addInteractable(door);

    // Place a lever in room 1 and pass the door that it should unlock
    Lever* lever = new Lever(door);
    room1->addInteractable(lever);

    // Assign the rooms to the game manager's room map.
    rooms[0] = room1;
    rooms[1] = room2;
}

// The game loop - this is where the player begins interacting with the world.
// The loop runs until the player decides to end the game.
void GameManager::startGame() {
    std::string command,
        object; // We listen for both the action and the target object.

    // Show the player's current status (where they are, inventory, etc.)
    player.displayStatus();

    // The main loop - the player navigates the world, one moment at a time.
    while (true) {
        rooms[player.getCurrentRoomId()]
            ->describe();  // Describe the player's surroundings.
        std::cout << "> "; // A quiet invitation for the player to act.
        std::cin >> command;

        if (command == "move") {
            std::string direction{};
            std::cin >> direction;

            int nextRoomId =
                rooms[player.getCurrentRoomId()]->getExit(direction);

            if (nextRoomId != -1) {
                // Iterate through the interactables in the current room to find
                // a Door
                bool doorLocked = false;
                for (Interactable* interactable :
                     rooms[player.getCurrentRoomId()]->getInteractables()) {
                    Door* door = dynamic_cast<Door*>(interactable);
                    if (door && door->isLockedState()) {
                        doorLocked = true;
                        break;
                    }
                }

                if (doorLocked) {
                    std::cout << "The door is locked. You can't go through."
                              << std::endl;
                } else {
                    player.move(
                        nextRoomId); // Movement, the simplest form of progress.
                }
            } else {
                std::cout << "You can't go that way!" << std::endl;
            }
        } else if (command == "interact") {
            std::cin >> object; // A moment of curiosity - the player reaches
                                // out to interact.
            rooms[player.getCurrentRoomId()]->interactWithObject(
                object); // Interact with something specific.
        }
    }
}
