#include "mapcreator.h"
#include "waycreator.h"
#include <cstdlib>

MapCreator::MapCreator(Position startPos, Position endPos, int mapSz) {
    // set map size
    map = new int*[mapSz];
    for (int i = 0; i < mapSz; i++) {
        map[i] = new int[mapSz];
    }

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
    WayCreator way(startPos, endPos, mapSz, true, map);

    //place garanteed way on map
    mapFiller(way.getWay(),1);

    //place disturbances
    for (int i = 0; i < mapSz; i++) {
        for (int l = 0; l < mapSz; l++) {
            // TODO i == 0 l == 0
            if (i != 0 &&
                    map[i-1][l] != 0 &&
                    map[i][l] == 0) {
                WayCreator d_way(Position(i-1,l), Position(), mapSz, false, map);
                mapFiller(d_way.getWay(),map[i-1][l] + rand() % 2);
            }
            if (l != 0 &&
                    map[i][l-1] != 0 &&
                    map[i][l] == 0) {
                WayCreator d_way(Position(i,l-1), Position(), mapSz, false, map);
                mapFiller(d_way.getWay(),map[i][l-1] + rand() % 2);
            }
        }
    }

}


int **MapCreator::getMap() const {
    return map;
}

void MapCreator::setMap(int **value) {
    map = value;
}

void MapCreator::mapFiller(std::vector<Position> way, int start) {
    for (int i = 0; i < way.size(); i++) {
        map[way[i].x][way[i].y] = start;
        start++;
    }

}
