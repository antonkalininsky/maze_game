#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <position.h>
#include <vector>


class MapCreator
{
public:
    MapCreator(Position startPos, Position endPos, int mapSz);

    int **getMap() const;
    void setMap(int **value);

private:
    int **map;
    int size;
    void mapFiller(std::vector<Position> way, int start = 1);
    std::vector<Position> findNeighbors(Position p);
    Position unpackNeighbor(int num, Position ps);
};

#endif // MAPCREATOR_H
