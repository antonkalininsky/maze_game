#include <QCoreApplication>
#include "iostream"

#include "cursor.h"
#include "funs.h"

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

    // creating current cursor
    Cursor curPos;
    curPos = sPos;

    // vector of steps
    vector<Cursor> way;
    way.push_back(curPos);

    // searching way from start to end
    while (!isSamePos(curPos,ePos)) {
        // basic movement
        if (curPos.x < ePos.x) {
            curPos.x++;
        } else if (curPos.x > ePos.x) {
            curPos.x--;
        } else if (curPos.y < ePos.y) {
            curPos.y++;
        } else if (curPos.y > ePos.y) {
            curPos.y--;
        }
        way.push_back(curPos);
    }

    // write way in a maze
    int cou;
    cou = 1;
    for (int i = 0; i < way.size(); i++) {
        maze[way[i].x][way[i].y] = cou;
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

