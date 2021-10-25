#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include "position.h"

class Tile : public QGraphicsRectItem
{
public:
    Tile(int sz);
    void keyPressEvent(QKeyEvent * e);
    int tileSz;
    Position Pos;
};

#endif // TILE_H
