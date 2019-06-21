#include "Player.h"
#include "Map.h"

#ifndef SOKOBAN_SESSION_H
#define SOKOBAN_SESSION_H


class Session {
private:
    Map map;
    Player player;
public:
    Session(int width, int height);
    Session() = default;
    Map getMap();
    void start();
    void finish();
    bool finished();
    Position getPlayerPosition();
    void loadMap(const string& mapName);
    void move(char direction);
    void reverse();
};


#endif //SOKOBAN_SESSION_H
