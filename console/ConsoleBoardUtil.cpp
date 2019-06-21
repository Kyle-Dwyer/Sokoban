#include "ConsoleBoardUtil.h"
#include "../Operation.h"

string ConsoleBoardUtil::getSymbol(char icon) const {
    switch (icon) {
        case ICON_BLANK_IN:
        case ICON_BLANK_OUT:
            return "　";
        case ICON_BOX:
            return "□";
        case ICON_OFF_TARGET:
            return "○";
        case ICON_ON_TARGET:
            return "●";
        case ICON_PLAYER:
            return "※";
        case ICON_WALL:
            return "■";
        default:
            wrongMapInfo(icon);
    }
    return std::__cxx11::string();
}

bool ConsoleBoardUtil::checkInput(char input) {
    switch (input) {
        case MOVE_UP:
        case MOVE_DOWN:
        case MOVE_LEFT:
        case MOVE_RIGHT:
        case MOVE_BACK:
        case QUIT: // to quit
            return true;
        case HELP: // to get help
            helpInfo();
            return false;
        default:
            wrongInputInfo();
            return false;
    }
}

void ConsoleBoardUtil::display(Map map) const {
    //cout << map.getHeight() << ":" << map.getWidth() << endl;
    //cout << map.getPlayerPosition().getX() <<":"<< map.getPlayerPosition().getY() <<endl;
    for (int i = 0; i < map.getHeight(); i++) {
        for (int j = 0; j < map.getWidth(); j++) {
            if (map.getPlayerPosition() == Position(i, j)) {
                cout << getSymbol(ICON_PLAYER);
            } else
                cout << getSymbol(map.get(Position(i, j)));
//            string symbol = getSymbol(map.getPlayerPosition() == Position(i, j) ? ICON_PLAYER : map.get(Position(i, j)));
        }
        cout << endl;
    }
}

char ConsoleBoardUtil::waitForInput() {
    while (true) {
        cout << "请输入你的指令： ";
        string input;
        cin >> input;
        if (input.size() == 1) {
            return input[0];
        } else {
            wrongInputInfo();
        }
    }
}

char ConsoleBoardUtil::chooseMapInfo() {
    while (true) {
        cout << "请输入选择的关卡（1-9）:  ";
        string input;
        cin >> input;
        if (input.size() == 1 && input[0] == HELP) {
            helpInfo();
            continue;
        }
        if (input.size() == 1 && input[0] > '0' && input[0] <= '9') {
            return input[0];
        } else {
            cout << "选择错误，请重新选择。" << endl;
        }
    }
}

void ConsoleBoardUtil::wrongMapInfo(char icon) const {
    cout << "ILLEGAL ICON " << icon;
}

void ConsoleBoardUtil::wrongInputInfo() {
    cout << "指令错误" << endl;
}

void ConsoleBoardUtil::helpInfo() {
    cout << "帮助信息：" << endl;
    cout << "图标说明：" << endl;
    cout << "○：没有放箱子的目标   ●：已经放置箱子的目标" << endl;
    cout << "※：玩家   ■：墙体   □：箱子" << endl;
    cout << "指令说明：" << endl;
    cout << "W：向上移动   A：向左移动   S：向下移动   D：向右移动   B：后退" << endl;
    cout << "H：帮助   Q：退出游戏" << endl;
}

void ConsoleBoardUtil::welcomeInfo() {
    cout << "来呀，来呀，来玩啊~" << endl;
    helpInfo();
}

void ConsoleBoardUtil::finishInfo() {
    cout << "游戏胜利" << endl;
}

void ConsoleBoardUtil::quitInfo() {
    cout << "退出游戏" << endl;
}
