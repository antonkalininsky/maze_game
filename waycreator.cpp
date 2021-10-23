#include "waycreator.h"
#include <cstdlib>
#include <time.h>
#include "funs.h"

WayCreator::WayCreator(Position sPos, Position ePos, int sz, bool isEndable, int **map){
    // vars
    int des;
    Position desPos,probPos;
    bool isRnd;

    // randomizing
    srand(time(NULL));

    // init conditions and restart position
    restartSearch:
    desPos = sPos;
    way.clear();
    way.push_back(desPos);
    checkedOpt.clear();
    isRnd = true;



    while (true) {
        // search for random and unused option
        do {
            des = std::rand() % 4;
        } while(isChecked(des));

        // do probable step
        probPos = desPos;
        switch (des) {
        case 0:
            if (isRnd) {
                probPos.y--;
            } else if (probPos.y > ePos.y) {
                probPos.y--;
            } else {
                probPos.y = -1;
            }
            break;
        case 1:
            if (isRnd) {
                probPos.x++;
            } else if (probPos.x < ePos.x) {
                probPos.x++;
            } else {
                probPos.x = -1;
            }
            break;
        case 2:
            if (isRnd) {
                probPos.y++;
            } else if (probPos.y < ePos.y) {
                probPos.y++;
            } else {
                probPos.y = -1;
            }
            break;
        case 3:
            if (isRnd) {
                probPos.x--;
            } else if (probPos.x > ePos.x) {
                probPos.x--;
            } else {
                probPos.y = -1;
            }
            break;
        default:
            break;
        }

        // check probable step for crossings
        if (isCrossing(probPos, sz, map)) {
            // add for checked ways
            checkedOpt.push_back(des);
            // check for aviliable ways
            if (checkedOpt.size() == 4) {
                if (isEndable) {
                    // start all over
                    goto restartSearch;
                } else {
                    way.erase(way.begin());
                    return;
                }
            }
        } else {
            // accept step
            desPos = probPos;
            way.push_back(probPos);
            checkedOpt.clear();
            // check for final step
            if (isSamePos(probPos,ePos)) {
                break;
            }
            // switch rnd mode
            if (isEndable) {
                isRnd = !isRnd;
            }
        }
    }
    return;
}

std::vector<Position> WayCreator::getWay() const{
    return way;
}

void WayCreator::setWay(const std::vector<Position> &value){
    way = value;
}

bool WayCreator::isChecked(int val) {
    for (int i = 0; i < checkedOpt.size(); i++) {
        if (val == checkedOpt[i]) {
            return true;
        }
    }
    return false;
}

bool WayCreator::isCrossing(Position C, int sz, int **map) {
    // check borders cross
    if (C.x < 0 ||
        C.y < 0 ||
        C.x >= sz ||
        C.y >= sz) {
        return true;
    }
    // check selfcross
    for (int i = 0; i < way.size(); i++) {
        if (C.x == way[i].x &&
                C.y == way[i].y) {
            return true;
        }
    }
    // check map cross
    if (map[C.x][C.y] != 0) {
        return true;
    }
    return false;
}
