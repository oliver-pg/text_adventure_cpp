#ifndef LEVER_H
#define LEVER_H

class Door;

#include "door.h"
#include "interactable.h"
#include <iostream>

// The Lever class is simple, like a small moment of choice in life.
// Pull it, and something changes. But once it's pulled, the decision is made.
class Lever : public Interactable {
    bool isPulled{}; // Tracks whether the lever has been pulled - once pulled,
                     // it's done.
    Door* connectedDoor{}; // The door that this lever controls.

  public:
    // Constructor - this lever starts unpulled, but now it also has a door to
    // affect.
    Lever(Door* door) : isPulled(false), connectedDoor(door) {}

    // The act of pulling the lever. Now it tries to interact with its door.
    void interact(Door* door = nullptr) {
        std::cout << "You pull the lever. You hear a click in the distance..."
                  << std::endl;

        Door* doorToInteract = door ? door : connectedDoor;

        // Check if the door exists before trying to interact with it.
        if (doorToInteract == nullptr) {
            std::cout << "There is no door connected to this lever."
                      << std::endl;
            return;
        }

        // The lever unlocks the door, just as a key unlocks possibilities.
        if (doorToInteract->isLockedState()) {
            doorToInteract->unlock();
            std::cout
                << "The door has been unlocked. A way forward is now open."
                << std::endl;
        } else {
            std::cout << "The lever seems to have no further effect. The door "
                         "is already unlocked."
                      << std::endl;
        }
    }
};

#endif // LEVER_H
