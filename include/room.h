#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <string>

class Room {
    std::string description{};
    std::map<std::string, int> exits{};

  public:
    Room(std::string desc);
    void addExit(const std::string& direction, int roomId);
    int getExit(const std::string& direction) const;
    void describe() const;
};

#endif // ROOM_H
