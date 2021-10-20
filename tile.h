#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>

class Tile : public QGraphicsRectItem
{
public:
    Tile();
    void keyPressEvent(QKeyEvent * e);
};

#endif // TILE_H
