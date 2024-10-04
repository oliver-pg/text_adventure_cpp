#ifndef LEVER_H
#define LEVER_H

class Door;

#include "door.h"
#include "interactable.h"
#include <iostream>

// The Lever class is simple, like a small moment of choice in life.
// Pull it, and something changes. But once it's pulled, the decision is made.
class Lever : public Interactable {
    bool isPulled; // Tracks whether the lever has been pulled - once pulled,
                   // it's done.

  public:
    // Constructor - we start with the lever unpulled. Everything is as it is.
    Lever() : isPulled(false) {}

    // The act of pulling the lever, but without context. In life, some actions
    // are empty unless they have meaning, like pulling a lever that isn't
    // connected to anything yet.
    void interact() override {
        std::cout << "You pull the lever. Nothing happens, as this isn't the "
                     "specific interact."
                  << std::endl;
    }

    // The act of pulling the lever - once pulled, it doesn't change back.
    // A reminder that actions often have irreversible consequences, even in
    // small things.
    void interact(Door* door);

    // Just checking if the lever has been pulled, like looking back at a past
    // decision.
    bool hasBeenPulled() const { return isPulled; }
};

#endif // LEVER_H
