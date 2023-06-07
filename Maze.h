#ifndef Maze_h
#define Maze_h

const int WIDTH = 22;
const int HEIGHT = 10;

class Maze
{
public:
    Maze();
    void movePlayer(char direction); 
    void print(); 
    bool isGameOver();
    void generateMaze(int startX, int startY, int endX, int endY); //生成迷宫

private:
    int maze[WIDTH][HEIGHT];
    int startX, startY;
    int endX, endY;
    int playerX, playerY; 


};

#endif /* Maze_h */
