#include <iostream>
#include "../Map.h"

#ifndef SOKOBAN_CONSOLEBOARDUTIL_H
#define SOKOBAN_CONSOLEBOARDUTIL_H



class ConsoleBoardUtil {
    string getSymbol(char icon) const;
public:
    void display(Map map) const ;
    bool checkInput(char input);
    char waitForInput();
    char chooseMapInfo();
    void wrongMapInfo(char icon) const;
    void wrongInputInfo();
    void helpInfo();
    void welcomeInfo();
    void finishInfo();
    void quitInfo();
};


#endif //SOKOBAN_CONSOLEBOARDUTIL_H
