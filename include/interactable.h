#ifndef INTERACTABLE_H
#define INTERACTABLE_H

// The Interactable class is like the essence of all objects you can interact
// with. It keeps things simple and pure, making sure all interactable things in
// life (or the game) have a shared foundation. It's an abstract class, so it's
// only here to guide others.
class Interactable {
  public:
    // A virtual destructor - just in case any derived classes need proper
    // clean-up.
    virtual ~Interactable() {}

    // The core of all interaction - but we leave the specifics to the derived
    // classes. Think of this like an invitation to act, a call to engage with
    // the world.
    virtual void interact() = 0;
};

#endif // INTERACTABLE_H
