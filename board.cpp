#include "board.h"
#include <QGraphicsRectItem>

Board::Board(int rectSz, int mapSz) {
    for (int i = 0; i < mapSz; i++) {
        for (int l = 0; l < mapSz; l++) {
            QGraphicsRectItem* tile = new QGraphicsRectItem();
            tile->setRect(0, 0, rectSz, rectSz);
            tile->setPos(tile->x() + i*rectSz, tile->y() + l*rectSz);
            addItem(tile);
        }
    }
}


