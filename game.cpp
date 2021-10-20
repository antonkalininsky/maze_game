#include "game.h"
#include "waycreator.h"
#include <cstdlib>

Game::Game() {
    Cursor A(0, 0),B(4, 4);
    initGame(A, B, 5);
}

void Game::initGame(Cursor startPos, Cursor endPos, int mapSz) {
    // set end and start
    ePos = endPos;
    sPos = startPos;
    cPos = sPos;

    // set map size
    map = new int*[mapSz];
    for (int i = 0; i < mapSz; i++) {
        map[i] = new int[mapSz];
    }

    // init map
    for (int i = 0; i < mapSz; i++) {
        for (int l = 0; l < mapSz; l++) {
            map[i][l] = 0;
        }
    }

    // create random way
    WayCreator way(startPos, endPos, mapSz);

    //place random way on map
    int cou;
    cou = 1;
    for (int i = 0; i < way.getWay().size(); i++) {
        map[way.getWay()[i].x][way.getWay()[i].y] = cou;
        cou++;
    }
    int maxValue = cou;

    //place disturbances
    for (int i = 0; i < mapSz; i++) {
        for (int l = 0; l < mapSz; l++) {
            if (map[i][l] == 0) {
                map[i][l] = rand() % maxValue + 1;
            }
        }
    }
}

bool Game::doStep(Cursor A) {
    if (map[A.x][A.y] > map[cPos.x][cPos.x]) {
        cPos = A;
        return true;
    } else {
        return false;
    }
}

int **Game::getMap() const
{
    return map;
}

void Game::setMap(int **value)
{
    map = value;
}

