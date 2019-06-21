#include "Session.h"
#include <fstream>
#include <iostream>
#include <sstream>

Session::Session(int width, int height) {
    map = Map(width, height);
}

Map Session::getMap() {
    return map;
}

void Session::start() {

}

void Session::finish() {

}

bool Session::finished() {
    return map.finished();
}

Position Session::getPlayerPosition() {
    return player.getPosition();
}

void Session::loadMap(const string &mapName) {
    ifstream file;
    file.open(mapName, ios::in);
    if (file.fail()) {
        cout << "The file " << mapName << " not found." << endl;
        return;
    }
    string line;
    getline(file, line);
    istringstream is(line);
    string str1, str2;
    is >> str1 >> str2;
    int width = stoi(str1);
    int height = stoi(str2);
    map = Map(width, height);
    for (int i = 0; i < height; i++) {
        getline(file, line);
        for (int j = 0; j < width; j++) {
            map.put(Position(i, j), line[j] - '0');
            if (line[j] - '0' >= 5 && line[j] - '0' < 9) {
                player = Player(i, j);
                map.setPlayerPos(i, j);
                map.put(Position(i, j), 2);
            }
        }
    }
    file.close();
//    Map temp = map;
//    cout << "debug" << endl;
}

void Session::move(char direction) {
    if (player.canMove(map, direction)) {
        map.move(getPlayerPosition(), player.getMovePos(direction));
        player.move(map, direction);
//        cout << player.recordPos.size() << endl;
//        cout << map.recordMap.size() << endl;
//        cout << player.getPosition().getX() << ":" << player.getPosition().getY() << endl;
//        cout << getPlayerPosition().getX() << ":" << getPlayerPosition().getY() << endl;
    }
}

void Session::reverse() {
    player.reverse();
    map.reverse(getPlayerPosition());
}

