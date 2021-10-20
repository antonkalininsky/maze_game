#include "tile.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

Tile::Tile(){



}

void Tile::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Left) {
        setPos(x()-10,y());
    }
    if (e->key() == Qt::Key_Right) {
        setPos(x()+10,y());
    }
    if (e->key() == Qt::Key_Up) {
        setPos(x(),y()-10);
    }
    if (e->key() == Qt::Key_Down) {
        setPos(x(),y()+10);
    }

}

