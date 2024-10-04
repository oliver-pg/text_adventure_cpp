#ifndef LEVER_H
#define LEVER_H

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

    // The act of pulling the lever - once pulled, it doesn't change back.
    // A reminder that actions often have irreversible consequences, even in
    // small things.
    void interact() override {
        if (!isPulled) {
            std::cout << "You pull the lever. You hear a mechanism activate."
                      << std::endl;
            isPulled = true;
        } else {
            std::cout << "The lever has already been pulled." << std::endl;
        }
    }

    // Just checking if the lever has been pulled, like looking back at a past
    // decision.
    bool hasBeenPulled() const { return isPulled; }
};

#endif // LEVER_H
