//#include <QCoreApplication>
#include <QApplication>
#include "iostream"
#include "cursor.h"
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

    Game game;
    Board *board = new Board(50, 5);


    // the window
    QMainWindow window;
    window.resize(800,600);
    window.setFixedSize(800,600);

    /*
    // the tile
    Tile *A = new Tile();
    A->setRect(0,0,50,50);

    // scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->addItem(A);
    A->setFlag(QGraphicsItem::ItemIsFocusable);
    A->setFocus();
    */

    // view
    QGraphicsView * view = new QGraphicsView(board);

    // windiw continue
    window.setCentralWidget(view);
    window.show();

    /*

    QWidget window;
    window.resize(800, 600);
    window.show();
    */
    //window


    return a.exec();
}

