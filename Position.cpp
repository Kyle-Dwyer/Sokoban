//
// Created by 10052 on 2019/6/11.
//

#include "Position.h"

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

Position Position::operator+(const Position &position) {
    return {x + position.x, y + position.y};
}

bool Position::operator==(const Position &position) const {
    return x == position.x && y == position.y;
}

void Position::setX(int x) {
    this->x = x;
}

void Position::setY(int y) {
    this->y = y;
}

void Position::setPosition(int x, int y) {
    setX(x);
    setY(y);
}
