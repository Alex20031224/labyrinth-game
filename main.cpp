#include "Maze.h"
#include <iostream>

using namespace std;

int main() {
    srand(time(NULL));
    Maze maze;
    int steps = 0;

    char direction;
    while (true) {
        maze.print();

        cout << "輸入移動方向(w：上, a：左, s：下, d：右, q: 離開): ";
        cin >> direction;

        if (direction == 'q') {
            break;
        }

        maze.movePlayer(direction);
        steps++;

        if (maze.isGameOver()) {
            cout << "恭喜你抵達終點！" << endl;
            system("PAUSE"); 
            break;
        }
    }

    cout << "總步數: " << steps << endl;

    return 0;
}
