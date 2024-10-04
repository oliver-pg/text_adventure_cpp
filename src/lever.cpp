#include "../include/lever.h"
#include "../include/door.h"
#include <iostream>

// The lever class represents a decision point in life.
// You pull it, and things change—sometimes in ways you don't expect.

// When the player interacts with the lever, the state of the world shifts.
// Perhaps something has been unlocked, a path forward revealed.
void Lever::interact(Door* door) {
    std::cout << "You pull the lever. You hear a click in the distance..."
              << std::endl;

    // The lever unlocks the door, just as a key unlocks possibilities.
    if (door->isLockedState()) {
        door->unlock();
        std::cout << "The door has been unlocked. A way forward is now open."
                  << std::endl;
    } else {
        std::cout << "The lever seems to have no further effect. The door is "
                     "already unlocked."
                  << std::endl;
    }
}
