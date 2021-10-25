//#include <QCoreApplication>
#include <QApplication>
#include "iostream"
#include "position.h"
#include "funs.h"
#include "waycreator.h"

#include "tile.h"

#include "game.h"
#include "board.h"

#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // the window
    QMainWindow window;
    window.resize(1200,1200);
    window.setFixedSize(1200,1200);

    // params
    int mapSize = 50;
    int rectSz = 20;

    // the game
    Game game(mapSize);

    // draw board
    Board *board = new Board(rectSz, mapSize, game.getMap());
    // put player
    Tile *tile = new Tile(rectSz);
    tile->setFlag(QGraphicsItem::ItemIsFocusable);
    tile->setFocus();
    board->addItem(tile);

    // view
    QGraphicsView * view = new QGraphicsView(board);

    // window continue
    window.setCentralWidget(view);
    window.show();


    return a.exec();
}

