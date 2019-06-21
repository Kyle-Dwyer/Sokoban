#include <vector>
#include "Session.h"

using namespace std;

#ifndef SOKOBAN_GAME_H
#define SOKOBAN_GAME_H


class Game {
private:
    vector<Session> sessions;
    Session currentSession;
public:
    Session startSession();
    void finishSession();
};


#endif //SOKOBAN_GAME_H
