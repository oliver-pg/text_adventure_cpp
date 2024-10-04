#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
    std::string name{};
    int currentRoomId{};
    std::vector<std::string> inventory{};

  public:
    Player(std::string playerName);
    void move(int newRoomId);
    void addItem(const std::string& item);
    void displayStatus() const;
    int getCurrentRoomId() const;
};

#endif // PLAYER_H
