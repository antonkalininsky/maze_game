#ifndef GAME_H
#define GAME_H

#include "cursor.h"

class Game {
public:
    Game(int sz);
    void initGame(Cursor startPos, Cursor endPos, int mapSz);
    bool doStep(Cursor A);

    int **getMap() const;
    void setMap(int **value);

private:
    Cursor sPos,ePos,cPos;
    int** map;
};

#endif // GAME_H
