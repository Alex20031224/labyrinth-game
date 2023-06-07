#ifndef Maze_h
#define Maze_h

const int WIDTH = 22;
const int HEIGHT = 10;

class Maze {
public:
    Maze();
    void generateMaze(int startX, int startY, int endX, int endY);
    void movePlayer(char direction); // 移動玩家
    void print(); // 輸出迷宮
    bool isGameOver(); // 檢查遊戲是否結束

private:
    int maze[WIDTH][HEIGHT];
    int startX, startY;
    int endX, endY;
    int playerX, playerY;
};

#endif /* Maze_h */
