#include "Position.h"
#include "Icon.h"
#include <vector>
#include <stack>

#ifndef SOKOBAN_MAP_H
#define SOKOBAN_MAP_H

using namespace std;

class Map {
private:
    Position playerPos;
    vector<vector<char>> map;
    //vectot<vectot<Chess*>>
    //map.getChess(p).moveTo(p1)

    int width;
    int height;
public:
    Map(int width, int height);
    Map():width(0),height(0){}
    char get(const Position &position);
    void put(const Position &position, char icon);
    bool finished();
    bool movable(Position position);
    bool hasBox(Position position);
    void move(Position position,Position movePos);
    void reverse(Position position);
    void setPlayerPos(int x,int y);
    int getHeight();
    int getWidth();
    Position getPlayerPosition();
    stack<vector<vector<char>>> recordMap;
};


#endif //SOKOBAN_MAP_H
