#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "player.h"
#include "room.h"
#include <map>

class GameManager {
    Player player;
    std::map<int, Room*> rooms{};

  public:
    GameManager(std::string playerName);
    ~GameManager();
    void initGame();
    void startGame();
};

#endif // GAME_MANAGER_H
