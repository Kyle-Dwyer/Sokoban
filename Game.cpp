//
// Created by 10052 on 2019/6/11.
//

#include "Game.h"

Session Game::startSession() {
    currentSession = Session();
    currentSession.start();
    return currentSession;
}

void Game::finishSession() {
    currentSession.finish();
    sessions.push_back(currentSession);
}
