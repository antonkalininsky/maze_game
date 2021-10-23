#include "board.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QString>
#include <QPen>
#include <QGraphicsLineItem>
#include "position.h"
#include <vector>
#include <QDebug>

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

    // draw maze
    bool isChecked[mapSz][mapSz];

    for (int i = 0; i < mapSz; i++) {
        for (int l = 0; l < mapSz; l++) {
            isChecked[i][l] = false;
        }
    }

    Position sPos(0,0),ePos,bufPos;

    std::vector<Position> checkQueue;

    checkQueue.push_back(sPos);

    while (checkQueue.size() > 0) {
        // search 4 smallest unit
        /*
        int smol = 0;
        repeat:
        for (int i = 0; i < checkQueue.size(); i++) {
            if (map[checkQueue[smol].x][checkQueue[smol].y] > map[checkQueue[i].x][checkQueue[i].y]) {
                smol = i;
                goto repeat;
            }
        }
        */
        // pop position 4 checking
        bufPos = checkQueue.back();
        checkQueue.pop_back();
        //bufPos = checkQueue.at(smol);
        //checkQueue.erase(checkQueue.begin() + smol);
        isChecked[bufPos.x][bufPos.y] = true;
        // checking
        for (int i = 0; i < 4; i++) {
            // in 4 directories
            int sumX,sumY;
            sumY = 0;
            sumY -= i == 0 ? 1 : 0;
            sumY += i == 2 ? 1 : 0;
            sumX = 0;
            sumX += i == 1 ? 1 : 0;
            sumX -= i == 3 ? 1 : 0;
            // if neighbor is in borders and not checked
            if ((bufPos.x + sumX >= 0) && (bufPos.x + sumX < mapSz) && (bufPos.y + sumY >= 0) && (bufPos.y + sumY < mapSz) &&
                    !isChecked[bufPos.x + sumX][bufPos.y + sumY]) {
                // add neighbor for checking
                checkQueue.push_back(Position(bufPos.x  + sumX, bufPos.y + sumY));
                // is line needed?
                //qDebug() << map[bufPos.x][bufPos.y];
                //qDebug() << map[bufPos.x + sumX][bufPos.y + sumY];
                if (map[bufPos.x][bufPos.y] + 1 != map[bufPos.x + sumX][bufPos.y + sumY]) {
                    QGraphicsLineItem* line = new QGraphicsLineItem();
                    line->setPen(pen2);
                    switch (i) {
                    case 0:
                        line->setLine(bufPos.x * rectSz, bufPos.y * rectSz, (bufPos.x + 1) * rectSz, bufPos.y * rectSz);
                        break;
                    case 1:
                        line->setLine((bufPos.x + 1) * rectSz, bufPos.y * rectSz, (bufPos.x + 1) * rectSz, (bufPos.y + 1) * rectSz);
                        break;
                    case 2:
                        line->setLine(bufPos.x * rectSz, (bufPos.y + 1) * rectSz, (bufPos.x + 1) * rectSz, (bufPos.y + 1) * rectSz);
                        break;
                    case 3:
                        line->setLine(bufPos.x * rectSz, bufPos.y * rectSz, bufPos.x * rectSz, (bufPos.y + 1) * rectSz);
                        break;
                    default:
                        break;
                    }
                    addItem(line);
                }
            }
        }
    }
}


