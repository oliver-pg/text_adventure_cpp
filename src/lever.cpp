#include "../include/lever.h"
#include "../include/door.h"
#include <iostream>

// Constructor - this lever starts unpulled, but now it also has a door to
// affect.
Lever::Lever(Door* door) : isPulled(false), connectedDoor(door) {}

// Override interact() method from Interactable
void Lever::interact() {
    interact(nullptr); // Delegate to the door-specific interact method
}

// The act of pulling the lever. Now it tries to interact with its door.
void Lever::interact(Door* door) {
    std::cout << "You pull the lever. You hear a click in the distance..."
              << std::endl;

    Door* doorToInteract = door ? door : connectedDoor;

    // Check if the door exists before trying to interact with it.
    if (doorToInteract == nullptr) {
        std::cout << "There is no door connected to this lever." << std::endl;
        return;
    }

    // The lever unlocks the door, just as a key unlocks possibilities.
    if (doorToInteract->isLockedState()) {
        doorToInteract->unlock();
        std::cout << "The door has been unlocked. A way forward is now open."
                  << std::endl;
    } else {
        std::cout << "The lever seems to have no further effect. The door is "
                     "already unlocked."
                  << std::endl;
    }
}
