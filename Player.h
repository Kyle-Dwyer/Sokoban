#include <map>
#include <stack>
#include "Position.h"
#include "Map.h"

#ifndef SOKOBAN_PLAYER_H
#define SOKOBAN_PLAYER_H

using namespace std;

class Player {
private:
    Position position{};

    map<char, Position> movePos;
public:
    Player() = default;
    Player(int x, int y);
    bool canMove(Map map, char direction);
    void move(Map map, char direction);
    void reverse();
    Position getPosition();
    Position getMovePos(char direction);
    stack<Position> recordPos;
};

#endif //SOKOBAN_PLAYER_H
