#ifndef ITEM_H
#define ITEM_H

#include <string>
class Item {
  public:
    Item(const std::string& name, const std::string& description, bool usable);

    std::string getName() const;
    std::string getDescription() const;
    bool isUsable() const;

    void use();

  private:
    std::string name{};
    std::string description{};
    bool usable{};
};

#endif
