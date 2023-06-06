#include "Maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

const int WALL = 0;
const int PATH = 1;
const int START = 2;
const int END = 3;
const int PLAYER = 4;

Maze::Maze() {
    // 初始化迷宫为墙壁
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[x][y] = WALL;
        }
    }

    startX = 1;
    startY = 1;
    endX = WIDTH - 2;
    endY = HEIGHT - 2;

    generateMaze(startX, startY, endX, endY);
    playerX = startX;
    playerY = startY;
    maze[playerX][playerY] = PLAYER;
}

void Maze::generateMaze(int startX, int startY, int endX, int endY) {
    stack<pair<int, int>> stack;
    maze[startX][startY] = START;
    maze[endX][endY] = END;
    stack.push(make_pair(startX, startY));

    while (!stack.empty()) {
        pair<int, int> current = stack.top();
        int x = current.first;
        int y = current.second;
        stack.pop();

        if (x == endX && y == endY) {
            break;
        }

        int directions[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int randomIndex = rand() % 4;
            int temp = directions[i];
            directions[i] = directions[randomIndex];
            directions[randomIndex] = temp;
        }

        for (int i = 0; i < 4; i++) {
            int dx = 0;
            int dy = 0;

            switch (directions[i]) {
                case 0: // 上
                    dy = -1;
                    break;
                case 1: // 右
                    dx = 1;
                    break;
                case 2: // 下
                    dy = 1;
                    break;
                case 3: // 左
                    dx = -1;
                    break;
            }

            int nx = x + (dx * 2);
            int ny = y + (dy * 2);

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[nx][ny] == WALL) {
                maze[nx][ny] = PATH;
                maze[x + dx][y + dy] = PATH;
                stack.push(make_pair(nx, ny));
            }
        }
    }
}

void Maze::movePlayer(char direction) {
    int dx = 0;
    int dy = 0;

    switch (direction) {
        case 'w': // 上
            dy = -1;
            break;
        case 'a': // 左
            dx = -1;
            break;
        case 's': // 下
            dy = 1;
            break;
        case 'd': // 右
            dx = 1;
            break;
        default:
            cout << "請輸入正確方向！" << endl;
            return;
    }

    int newX = playerX + dx;
    int newY = playerY + dy;

    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newX][newY] != WALL) {
        maze[playerX][playerY] = PATH;
        maze[newX][newY] = PLAYER;
        playerX = newX;
        playerY = newY;
    } else {
        cout << "此路不通，請重新移動" << endl;
    }
}

void Maze::print() {
    for (int y = -1; y < HEIGHT + 1; y++) {
        for (int x = -1; x < WIDTH + 1; x++) {
            if (x == -1 || x == WIDTH || y == -1 || y == HEIGHT) {
                cout << "██";
            } else {
                switch (maze[x][y]) {
                    case WALL:
                        cout << "██";
                        break;
                    case PATH:
                        cout << "  ";
                        break;
                    case START:
                        cout << "S ";
                        break;
                    case END:
                        cout << "E ";
                        break;
                    case PLAYER:
                        cout << "P ";
                        break;
                }
            }
        }
        cout << endl;
    }
}

bool Maze::isGameOver() {
    return playerX == endX && playerY == endY;
}
