#include "board.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QString>
#include <QPen>
#include <QGraphicsLineItem>


Board::Board(int rectSz, int mapSz, int **map) {

    QPen pen;
    pen.setColor(Qt::gray);
    pen.setStyle(Qt::DotLine);


    QPen pen2;
    pen2.setColor(Qt::black);
    pen2.setStyle(Qt::SolidLine);
    pen2.setWidth(3);

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

    // borders
    QGraphicsLineItem* line = new QGraphicsLineItem();
    line->setLine(0, 0, 0, mapSz*rectSz);
    line->setPen(pen2);
    addItem(line);
    line = new QGraphicsLineItem();
    line->setLine(0, 0, mapSz*rectSz, 0);
    line->setPen(pen2);
    addItem(line);
    line = new QGraphicsLineItem();
    line->setLine(0, mapSz*rectSz, mapSz*rectSz, mapSz*rectSz);
    line->setPen(pen2);
    addItem(line);
    line = new QGraphicsLineItem();
    line->setLine(mapSz*rectSz, 0, mapSz*rectSz, mapSz*rectSz);
    line->setPen(pen2);
    addItem(line);

    // maze
    for (int i = 0; i < mapSz; i++) {
        for (int l = 0; l < mapSz; l++) {
            line = new QGraphicsLineItem();
            line->setPen(pen2);
            if (map[i][l] >= map[i][l+1]) {
                line->setLine(i*rectSz, rectSz*(1+l), rectSz, rectSz*(1+l));
                addItem(line);
            }
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


