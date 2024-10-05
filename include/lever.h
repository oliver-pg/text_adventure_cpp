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
    Lever(Door* door);

    // Override the interact method from the base class
    void interact() override;

    // The act of pulling the lever. Now it tries to interact with its door.
    void interact(Door* door = nullptr);
};

#endif // LEVER_H
