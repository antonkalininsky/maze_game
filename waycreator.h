#ifndef WAYCREATOR_H
#define WAYCREATOR_H

#include "position.h"
#include <vector>


class WayCreator
{
public:
    WayCreator(Position sPos, Position ePos, int sz, bool isEndable, int **map);

    std::vector<Position> getWay() const;
    void setWay(const std::vector<Position> &value);

private:
    std::vector<Position> way;
    std::vector<int> checkedOpt;

    bool isChecked(int val);
    bool isCrossing(Position C, int sz, int **map);

};

#endif // WAYCREATOR_H
