#ifndef GAME_H
#define GAME_H

#include "position.h"

class Game {
public:
    Game(int sz);
    void initGame(Position startPos, Position endPos, int mapSz);
    bool doStep(Position A);

    int **getMap() const;
    void setMap(int **value);

private:
    Position sPos,ePos,cPos;
    int** map;
    int mapSize;
    void createDisturbances();
};

#endif // GAME_H
