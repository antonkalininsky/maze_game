#include <QCoreApplication>
#include "iostream"

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

    // showing
    for (int i = 0; i < SIZE; i++) {
        for (int l = 0; l < SIZE; l++) {
            cout << maze[i][l];
            cout << "   ";
        }
        cout << endl;
    }

    return a.exec();
}

