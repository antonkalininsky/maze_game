#ifndef WAYCREATOR_H
#define WAYCREATOR_H

#include "cursor.h"
#include <vector>


class WayCreator
{
public:
    WayCreator(int sz, Cursor ePos, Cursor sPos);

    std::vector<Cursor> getWay() const;
    void setWay(const std::vector<Cursor> &value);

private:
    std::vector<Cursor> way;
    std::vector<int> checkedOpt;

    bool isChecked(int val);
    bool isCrossing(Cursor C, int sz);
};

#endif // WAYCREATOR_H
