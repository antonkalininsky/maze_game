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

//using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int mapSize = 30;

    Game game(mapSize);

    int map[mapSize][mapSize];

    for (int i = 0; i < mapSize; i ++) {
        for (int l = 0; l < mapSize; l ++) {
            map[i][l] = game.getMap()[i][l];
        }

    }


    Board *board = new Board(30, mapSize, game.getMap());


    // the window
    QMainWindow window;
    window.resize(1000,1000);
    window.setFixedSize(1000,1000);

    // view
    QGraphicsView * view = new QGraphicsView(board);

    // window continue
    window.setCentralWidget(view);
    window.show();


    return a.exec();
}

