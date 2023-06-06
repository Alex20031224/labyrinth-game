//
//  Maze.h
//  Object-Oriented Programming and Internships 小專題
//
//  Created by Alex on 2023/6/6.
//

#ifndef Maze_h
#define Maze_h

const int WIDTH = 22;
const int HEIGHT = 10;

class Maze {
public:
    Maze();
    void generate(); // 生成迷宫
    void movePlayer(char direction); // 移動玩家
    void print(); // 輸出迷宮
    bool isGameOver(); // 检查遊戲是否結束

private:
    int maze[WIDTH][HEIGHT];
    int startX, startY;
    int endX, endY;
    int playerX, playerY;

    void generateMaze(int startX, int startY, int endX, int endY);
};

#endif /* Maze_h */
