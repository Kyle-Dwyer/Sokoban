

#ifndef SOKOBAN_POSITION_H
#define SOKOBAN_POSITION_H


class Position {
private:
    int x;
    int y;
public:
    Position(int x, int y) : x(x), y(y) {}

    Position() = default;

    int getX() const;

    int getY() const;

    Position operator+(const Position &position);

    bool operator==(const Position &position) const;

    void setX(int x);

    void setY(int y);

    void setPosition(int x,int y);
};


#endif //SOKOBAN_POSITION_H
