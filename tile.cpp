#include "tile.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QBrush>

Tile::Tile(int sz) {

    tileSz = sz;

    QBrush b;
    b.setColor(Qt::red);
    b.setStyle(Qt::SolidPattern);
    setRect(0, 0, sz*0.4, sz*0.4);
    setPos(x()+sz*0.3, y()+sz*0.3);
    setBrush(b);

}

void Tile::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Left) {
        setPos(x()-tileSz,y());
    }
    if (e->key() == Qt::Key_Right) {
        setPos(x()+tileSz,y());
    }
    if (e->key() == Qt::Key_Up) {
        setPos(x(),y()-tileSz);
    }
    if (e->key() == Qt::Key_Down) {
        setPos(x(),y()+tileSz);
    }

}

