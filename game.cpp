#include "game.h"
#include "mapcreator.h"
#include <cstdlib>
#include <vector>
#include "position.h"

Game::Game(int sz) {
    Position A(0, 0),B(sz-1, sz-1);
    initGame(A, B, sz);
    mapSize = sz;
}

void Game::initGame(Position startPos, Position endPos, int mapSz) {
    // set end and start
    ePos = endPos;
    sPos = startPos;
    cPos = sPos;

    // set map size
    map = new int*[mapSz];
    for (int i = 0; i < mapSz; i++) {
        map[i] = new int[mapSz];
    }

    // create n save map
    MapCreator theMap(startPos, endPos, mapSz);
    map = theMap.getMap();

}

bool Game::doStep(Position A) {
    if (map[A.x][A.y] > map[cPos.x][cPos.x]) {
        cPos = A;
        return true;
    } else {
        return false;
    }
}

int **Game::getMap() const {
    return map;
}

void Game::setMap(int **value) {
    map = value;
}

