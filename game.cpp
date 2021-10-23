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

void Game::createDisturbances() {
    /*
    for (int i = 0; i < mapSize; i++) {
        for (int l = 0; l < mapSize; l++) {
            if (map[i][l] == 0) {
                if (i == 0) {
                    map[0][l] = 1;
                } else {
                    map[i][l] = map[i-1][l] + 1;
                }
                Position bufPos;
                int cou;
                std::vector<Position> checkQueue;
                checkQueue.push_back(Position(i,l));
                while (checkQueue.size() > 0) {
                    // pop position 4 checking
                    bufPos = checkQueue.back();
                    checkQueue.pop_back();
                    cou = map[bufPos.x][bufPos.y];

                }
            }
        }
    }





        // checking
        for (int i = 0; i < 4; i++) {
            // in 4 directories
            int sumX,sumY;
            sumY = 0;
            sumY -= i == 0 ? 1 : 0;
            sumY += i == 2 ? 1 : 0;
            sumX = 0;
            sumX += i == 1 ? 1 : 0;
            sumX -= i == 3 ? 1 : 0;
            // if neighbor is in borders and not checked
            if ((bufPos.x + sumX >= 0) && (bufPos.x + sumX < mapSz) && (bufPos.y + sumY >= 0) && (bufPos.y + sumY < mapSz) &&
                    !isChecked[bufPos.x + sumX][bufPos.y + sumY]) {
                // add neighbor for checking
                checkQueue.push_back(Position(bufPos.x  + sumX, bufPos.y + sumY));
                // is line needed?
                if (map[bufPos.x][bufPos.y] + 1 != map[bufPos.x + sumX][bufPos.y + sumY]) {
                    QGraphicsLineItem* line = new QGraphicsLineItem();
                    line->setPen(pen2);
                    switch (i) {
                    case 0:
                        line->setLine(bufPos.x * rectSz, bufPos.y * rectSz, (bufPos.x + 1) * rectSz, bufPos.y * rectSz);
                        break;
                    case 1:
                        line->setLine((bufPos.x + 1) * rectSz, bufPos.y * rectSz, (bufPos.x + 1) * rectSz, (bufPos.y + 1) * rectSz);
                        break;
                    case 2:
                        line->setLine(bufPos.x * rectSz, (bufPos.y + 1) * rectSz, (bufPos.x + 1) * rectSz, (bufPos.y + 1) * rectSz);
                        break;
                    case 3:
                        line->setLine(bufPos.x * rectSz, bufPos.y * rectSz, bufPos.x * rectSz, (bufPos.y + 1) * rectSz);
                        break;
                    default:
                        break;
                    }
                    addItem(line);
                }
            }
        }
    }
    */
}

