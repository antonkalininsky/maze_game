#include "mapcreator.h"
#include "waycreator.h"
#include <cstdlib>
#include <time.h>

MapCreator::MapCreator(Position startPos, Position endPos, int mapSz) {
    // set map size
    size = mapSz;
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

    // way size
    int waySz = way.getWay().size();

    //place garanteed way on map
    mapFiller(way.getWay(),1);

    // random way disturbances
    srand(time(NULL));
    // dist for right way
    for (int i = 0; i < way.getWay().size(); i++) {
        if (i % 5 == 0) {
            WayCreator d_way(Position(way.getWay()[i].x, way.getWay()[i].y), Position(), mapSz, false, map);
            mapFiller(d_way.getWay(),map[way.getWay()[i].x][way.getWay()[i].y]+1);//rand() % 2);
        }
    }
    // rnd dist
    for (int i = 0; i < mapSz; i++) {
        for (int l = mapSz-1; l >= 0; l--) {
            if (map[i][l] == 0) {
                if (l != 0 && map[i][l-1] != 0) {
                    WayCreator d_way(Position(i,l-1), Position(), mapSz, false, map);
                    mapFiller(d_way.getWay(),map[i][l-1] + rand() % 10);
                } else if (i != 0 && map[i-1][l] != 0 && map[i][l] == 0) {
                    WayCreator d_way(Position(i-1,l), Position(), mapSz, false, map);
                    mapFiller(d_way.getWay(),map[i-1][l] + rand() % 10);
                } else {
                    WayCreator d_way(Position(i,l), Position(), mapSz, false, map);
                    mapFiller(d_way.getWay(),rand() % waySz);
                }

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

std::vector<Position> MapCreator::findNeighbors(Position p) {
    std::vector<Position> v;
    // 0 - up
    if (p.y != 0 && (map[p.x][p.y-1] - map[p.x][p.y] == 1 || map[p.x][p.y-1] - map[p.x][p.y] == -1)) {
        v.push_back(Position(p.x,p.y-1));
    }
    // 1 - right
    if (p.x != size-1 && (map[p.x+1][p.y] - map[p.x][p.y] == 1 || map[p.x+1][p.y] - map[p.x][p.y] == -1)) {
        v.push_back(Position(p.x+1,p.y));
    }
    // 2 - down
    if (p.y != size-1 && (map[p.x][p.y+1] - map[p.x][p.y] == 1 || map[p.x][p.y+1] - map[p.x][p.y] == -1)) {
        v.push_back(Position(p.x,p.y+1));
    }
    // 3 - left
    if (p.x != 0 && (map[p.x-1][p.y] - map[p.x][p.y] == 1 || map[p.x-1][p.y] - map[p.x][p.y] == -1)) {
        v.push_back(Position(p.x-1,p.y));
    }
    /*
    // 0 - up
    if (p.y != 0 && map[p.x][p.y-1] != 0) {
        v.push_back(Position(p.x,p.y-1));
    }
    // 1 - right
    if (p.x != size-1 && map[p.x+1][p.y] != 0) {
        v.push_back(Position(p.x+1,p.y));
    }
    // 2 - down
    if (p.y != size-1 && map[p.x][p.y+1] != 0) {
        v.push_back(Position(p.x,p.y+1));
    }
    // 3 - left
    if (p.x != 0 && map[p.x-1][p.y] != 0) {
        v.push_back(Position(p.x-1,p.y));
    }
    */
    return v;
}

Position MapCreator::unpackNeighbor(int num, Position ps) {
    switch (num) {
    case 0:
        ps.y--;
        break;
    case 1:
        ps.x++;
        break;
    case 2:
        ps.y++;
        break;
    case 3:
        ps.x--;
        break;
    default:
        break;
    }
    return ps;
}


