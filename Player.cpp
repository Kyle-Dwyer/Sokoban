#include "Player.h"
#include "Operation.h"

Player::Player(int x, int y) {
    position = Position(x, y);
    movePos.insert(pair<char, Position>(MOVE_UP, Position(-1, 0)));
    movePos.insert(pair<char, Position>(MOVE_DOWN, Position(1, 0)));
    movePos.insert(pair<char, Position>(MOVE_LEFT, Position(0, -1)));
    movePos.insert(pair<char, Position>(MOVE_RIGHT, Position(0, 1)));
}

bool Player::canMove(Map map, char direction) {
    Position newPos = position + movePos.find(direction)->second;
    Position newBoxPos = newPos + movePos.find(direction)->second;
    if (map.movable(newPos))
        return true;
    return map.hasBox(newPos) && map.movable(newBoxPos);
}

void Player::move(Map map, char direction) {
    Position newPos = position + movePos.find(direction)->second;
    if (canMove(map, direction)) {
        recordPos.push(position);
        position.setPosition(newPos.getX(), newPos.getY());
    }
}

void Player::reverse() {
    if (recordPos.empty())
        return;
    position = recordPos.top();
    recordPos.pop();
}

Position Player::getPosition() {
    return position;
}

Position Player::getMovePos(char direction) {
    return movePos.find(direction)->second;
}
