#include <QCoreApplication>
#include "iostream"

#include "cursor.h"
#include "funs.h"
#include "waycreator.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // creating variables
    const int SIZE = 5;
    int maze[SIZE][SIZE];

    // init
    for (int i = 0; i < SIZE; i++) {
        for (int l = 0; l < SIZE; l++) {
            maze[i][l] = 0;
        }
    }

    // start and end positions
    Cursor sPos, ePos;
    sPos.x = 0;
    sPos.y = 0;
    ePos.x = 4;
    ePos.y = 4;

    // the way creator
    WayCreator way(SIZE,ePos,sPos);

    // write way in a maze
    int cou;
    cou = 1;
    for (int i = 0; i < way.getWay().size(); i++) {
        maze[way.getWay()[i].x][way.getWay()[i].y] = cou;
        cou++;
    }
    int maxValue = cou;


    // write disturbances
    for (int i = 0; i < SIZE; i++) {
        for (int l = 0; l < SIZE; l++) {
            if (maze[i][l] == 0) {
                maze[i][l] = rand() % maxValue + 1;
            }
        }
    }


    // showing
    for (int i = 0; i < SIZE; i++) {
        cout << "   ";
        for (int l = 0; l < SIZE; l++) {
            cout << maze[i][l];
            cout << "   ";
        }
        cout << endl;
    }

    return a.exec();
}

