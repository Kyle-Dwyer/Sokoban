#include "Map.h"

Map::Map(int width, int height) {
    this->width = width;
    this->height = height;
    for (int i = 0; i < height; ++i) {
        vector<char> temp(width);
        for (int j = 0; j < width; ++j) {
            temp[j] = ICON_WALL;
        }
        map.push_back(temp);
    }
}

char Map::get(const Position &position) {
    int x = position.getX();
    int y = position.getY();
    if (x < height && y < width)
        return map[x][y];
    return 0;
}

void Map::put(const Position &position, char icon) {
    int x = position.getX();
    int y = position.getY();
    if (x < height && y < width)
        map[x][y] = icon;
}

bool Map::finished() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (map[i][j] == ICON_BOX) {
                return false;
            }
        }
    }
    return true;
}

bool Map::movable(Position position) {
    char icon = get(position);
    return icon == ICON_BLANK_IN || icon == ICON_OFF_TARGET;
}

bool Map::hasBox(Position position) {
    char icon = get(position);
    return icon == ICON_BOX || icon == ICON_ON_TARGET;
}

void Map::move(Position position, Position movePos) {
    recordMap.push(map);
    Position newPos = position + movePos;
    Position newBoxPos = newPos + movePos;
    if (get(newPos) == ICON_BOX && get(newBoxPos) == ICON_BLANK_IN) {
        put(newBoxPos, ICON_BOX);
        put(newPos, ICON_BLANK_IN);
    } else if (get(newPos) == ICON_BOX && get(newBoxPos) == ICON_OFF_TARGET) {
        put(newBoxPos, ICON_ON_TARGET);
        put(newPos, ICON_BLANK_IN);
    } else if (get(newPos) == ICON_ON_TARGET && get(newBoxPos) == ICON_BLANK_IN) {
        put(newBoxPos, ICON_BOX);
        put(newPos, ICON_OFF_TARGET);
    } else if (get(newPos) == ICON_ON_TARGET && get(newBoxPos) == ICON_OFF_TARGET) {
        put(newBoxPos, ICON_ON_TARGET);
        put(newPos, ICON_OFF_TARGET);
    }
    playerPos.setPosition(newPos.getX(), newPos.getY());
}

void Map::reverse(Position position) {
    if (recordMap.empty())
        return;
    map = recordMap.top();
    recordMap.pop();
    playerPos.setPosition(position.getX(), position.getY());
}

void Map::setPlayerPos(int x, int y) {
    playerPos = Position(x, y);
}

int Map::getHeight() {
    return height;
}

int Map::getWidth() {
    return width;
}

Position Map::getPlayerPosition() {
    return {playerPos.getX(),playerPos.getY()};
}


