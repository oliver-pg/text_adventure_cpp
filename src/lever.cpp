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

// Life is full of levers, and sometimes pulling them opens doors.
void Lever::interact(Door* door) {
    std::cout << "You pull the lever. You hear a click in the distance..."
              << std::endl;

    // We check if the lever is connected to a door, or if the provided door is
    // valid.
    Door* doorToInteract = door ? door : connectedDoor;

    // If there's no door, we gently remind the player that not every action
    // leads somewhere.
    if (doorToInteract == nullptr) {
        std::cout << "There is no door connected to this lever." << std::endl;
        return;
    }

    // Now, if the door is locked, we unlock it, just like how we unlock new
    // opportunities.
    if (doorToInteract->isLockedState()) {
        doorToInteract->unlock();
        std::cout << "The door has been unlocked. A way forward is now open."
                  << std::endl;
    } else {
        // If the door is already unlocked, the lever doesn’t do anything more.
        std::cout << "The lever seems to have no further effect. The door is "
                     "already unlocked."
                  << std::endl;
    }
}
