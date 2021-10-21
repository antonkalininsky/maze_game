#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>

class Board : public QGraphicsScene {
public:
    Board(int rectSz, int mapSz, int **map);
};

#endif // BOARD_H
