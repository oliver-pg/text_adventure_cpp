#include "../include/item.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& description, bool usable)
    : name(name), description(description), usable(usable) {}

std::string Item::getName() const { return name; }

std::string Item::getDescription() const { return description; }

bool Item::isUsable() const { return usable; }

void Item::use() {
    if (usable) {
        std::cout << "You use the " << name << "." << std::endl;

    } else {
        std::cout << "The " << name << " cannot be used right now."
                  << std::endl;
    }
}
