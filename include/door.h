#ifndef DOOR_H
#define DOOR_H

#include "interactable.h"
#include <iostream>

// The Door class - it's a symbol of transitions, opportunities, or barriers.
// Locked at first, but unlock it, and you can move forward.
class Door : public Interactable {
    bool isLocked; // A simple state of being - locked or unlocked.

  public:
    // Constructor - by default, doors are locked. Like some of life's paths,
    // you need to find a key or a solution to open them.
    Door() : isLocked(true) {}

    // Interact with the door - check if it's locked or unlocked.
    // Doors remind us that not all obstacles are permanent; some just need a
    // bit of work.
    void interact() override {
        if (isLocked) {
            std::cout
                << "The door is locked. You need to find a way to unlock it."
                << std::endl;
        } else {
            std::cout << "You open the door and move to the next room."
                      << std::endl;
        }
    }

    // Unlock the door - you've found the key, pulled the lever, or otherwise
    // freed the way forward.
    void unlock() { isLocked = false; }

    // Just a way to check if the door is still locked.
    bool isLockedState() const { return isLocked; }
};

#endif // DOOR_H
