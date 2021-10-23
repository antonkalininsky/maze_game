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
    void mapFiller(std::vector<Position> way, int start = 1);
};

#endif // MAPCREATOR_H
