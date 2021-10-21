#include "board.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QString>
#include <QPen>


Board::Board(int rectSz, int mapSz, int **map) {

    QPen pen;
    pen.setColor(Qt::gray);
    pen.setStyle(Qt::DotLine);

    // draw squares n numbers
    for (int i = 0; i < mapSz; i++) {
        for (int l = 0; l < mapSz; l++) {
            QGraphicsTextItem* num = new QGraphicsTextItem();
            QGraphicsRectItem* tile = new QGraphicsRectItem();
            num->setPlainText(QString::number(map[i][l]));
            tile->setRect(0, 0, rectSz, rectSz);
            num->setPos(tile->x() + i*rectSz, tile->y() + l*rectSz);
            tile->setPos(tile->x() + i*rectSz, tile->y() + l*rectSz);
            tile->setPen(pen);
            addItem(tile);
            addItem(num);
        }
    }




    // draw borders

/*
    for (int i = 0; i < mapSz; i++) {
        for (int l = 0; l < mapSz; l++) {
            QLabel* num = new QLabel(tile);
            num->setText(QString::number(map[i][l]));
            //num->setGeometry(QRectF(0, 0, i*rectSz, l*rectSz));
            //addItem(num);
            addText(QString::number(map[i][l]));

        }
    }
*/

}


