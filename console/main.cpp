#include <iostream>
#include "ConsoleBoardUtil.h"
#include "../Session.h"
#include "../Game.h"
#include "../Operation.h"

ConsoleBoardUtil consoleBoardUtil;

bool playOneSession(Session session) {
    session.start();
    char order;

    while (!session.finished()) {
        consoleBoardUtil.display(session.getMap());
        order = consoleBoardUtil.waitForInput();
        if (order > '0' && order <= '9') {
            string mapName("../maps/");
            mapName = mapName + order + ".map";
            session.loadMap(mapName);
            continue;
        }
        if (consoleBoardUtil.checkInput(order)) { // A W S D B Q
            if (order == MOVE_BACK) {
                session.reverse();
            } else if (order == QUIT) {
                consoleBoardUtil.quitInfo();
                return false;
            } else
                session.move(order);
        }

    }
    consoleBoardUtil.display(session.getMap());
    consoleBoardUtil.finishInfo();
    session.finish();
}

int main() {
    Game game;
    Session session;
    consoleBoardUtil.welcomeInfo();
    do {
        string mapName("../maps/");
        char level = consoleBoardUtil.chooseMapInfo();
        mapName = mapName + level + ".map";
        session.loadMap(mapName);
    } while (playOneSession(session));
    return 0;
}