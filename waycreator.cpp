#include "waycreator.h"

#include <cstdlib>
#include <time.h>
#include "funs.h"

WayCreator::WayCreator(int sz, Cursor ePos, Cursor sPos){
    // variables
    int des;
    Cursor desPos,probPos;

    // randomizing
    srand(time(NULL));

    // init conditions and restart position
    restartSearch:
    desPos = sPos;
    way.clear();
    way.push_back(desPos);
    checkedOpt.clear();

    while (true) {
        // search for random and unused option
        do {
            des = std::rand() % 4;
        } while(isChecked(des));

        // do probable step
        probPos = desPos;
        switch (des) {
        case 0:
            probPos.y--;
            break;
        case 1:
            probPos.x++;
            break;
        case 2:
            probPos.y++;
            break;
        case 3:
            probPos.x--;
            break;
        default:
            break;
        }

        // check probable step for crossings
        if (isCrossing(probPos, sz)) {
            // add for checked ways
            checkedOpt.push_back(des);
            // check for aviliable ways
            if (checkedOpt.size() == 4) {
                // start all over
                goto restartSearch;
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
        }
    }
}

std::vector<Cursor> WayCreator::getWay() const{
    return way;
}

void WayCreator::setWay(const std::vector<Cursor> &value){
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

bool WayCreator::isCrossing(Cursor C, int sz) {
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
    return false;
}
