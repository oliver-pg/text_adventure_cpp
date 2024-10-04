#include "../include/room.h"
#include <iostream>

Room::Room(std::string desc) : description(desc) {}

void Room::addExit(const std::string& direction, int roomId) {
    exits[direction] = roomId;
}

int Room::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second;
    }
    return -1;
}

void Room::describe() const { std::cout << description << std::endl; }
