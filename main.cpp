#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;
class Maze
{
private:
int width;
int height;
int mazeData[][];
pair<int, int> start;
pair<int, int> end;
public:
Maze(int width, int height){
    this->width = width;
    this->height = height;
}

void loadFromFile(string filename){
}

void setStart(int x, int y){
    this->start = make_pair(x, y);
}

void setEnd(int x, int y){
    this->end = make_pair(x, y);
}

pair <int, int> getEnd (){
  return makepair(end.first, end.second);
}

friend bool isWall(int x, int y);
};

bool isWall(int x, int y){
    return true;
}


class Position
{
private:
int x;
int y;

public:
Position(int x, int y){
    setX(x);
    setY(y);
}

int getX(){
    return this->x;
}

int getY(){
    return this->y;
}

void setX(int x){
    this->x = x;
}

void setY(int y){
    this->y = y;
}
};

class Direction
{
private:
int dx;
int dy;

public:
Direciton(int dx, int dy){
    this->dx = dx;
    this->dy = dy;
}

int getX(){
    return this->dx;
}

int getY(){
    return this->dy;
}
};

class Player
{
private:
Position position;

public:
bool move(Direciton direction){
    if (isWall(direction.getX(), direction.getY())) {
        // if the next position is not the wall or out of the map
        // update position
        position.setX(direction.getX());
        position.setY(direction.getY());
    return true;
    } else {
        // error handling
        cout << "Invalid movement" << endl;
    return false;
    }
}

Position& getPosition(){
    return position;
}
};

class Game 
{
private:
Player player;
Maze maze;
public:
void start(){
  //loadfromfile();
  //Maze(x,y)
  //setStart (x,y)
  //player.position(x,y);
  //setEnd()
}
bool update () {
  // input movement
  // judge valid or not
  // if yes, draw map , else input again
  // determine if arrives the endpoint
  int mx, my;
  cout <<"請輸入要移動的位置：";
  cin >> mx >>my;
  Direction direction (mx, my);
  do {
  } while(!player.move (direction));
  draw ();

  return checkEndGame(maze, player);
}
void draw (){
  
      int i,j;
  for(int i=0; i<maze.height; i++) //輸出地圖
    {
        for(int j=0; j<maze.width; j++)
        {
            if(j==maze.height-1||j==0)
            {
                if(j==0 && i==0)
                {
                    cout<<"";
                }
                else if(i==0 && j==maze.height-1)
                {
                    cout<<"";
                }
                else
                {
                    cout<<"|";
                }
            }
            else if(i==maze.height-1||i==0)
            {
                cout<<"";
            }
            else
            {
                cout<<(maze.mazeData[i][j]==1?"|":"_");
            }
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool checkEndGame (Maze maze, Player player) {
  Position position = player.getPosition();

  if( (maze.getEnd().first == position.getX()) &&
      (maze.getEnd().second == position.getY())) {
        return true
    }
  return false;
};

const int WIDTH = 22;
const int HEIGHT = 10;

class Cell {
public:
    int x;
    int y;
    int type;

    static const int WALL = 0;  // 定义墙的类型常量
    static const int PATH = 1;  // 定义路径的类型常量
    static const int START = 2;  // 定义起点的类型常量
    static const int END = 3;  // 定义终点的类型常量
};

void generateMaze(Cell maze[WIDTH][HEIGHT], int startX, int startY, int endX, int endY) {
    stack<Cell> stack;
    Cell startCell = {startX, startY, Cell::START};  // 创建起点Cell对象
    Cell endCell = {endX, endY, Cell::END};  // 创建终点Cell对象

    maze[startX][startY] = startCell;  // 将起点设置为起始位置的Cell
    maze[endX][endY] = endCell;  // 将终点设置为结束位置的Cell
    stack.push(startCell);  // 将起点Cell推入栈中

    while (!stack.empty()) {  // 当栈非空时进行迷宫生成
        Cell current = stack.top();  // 取出栈顶的Cell
        int x = current.x;
        int y = current.y;
        stack.pop();  // 弹出栈顶的Cell

        if (x == endX && y == endY) {  // 判断是否到达终点
            break;
        }

        // 生成随机方向
        int directions[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int randomIndex = rand() % 4;
            int temp = directions[i];
            directions[i] = directions[randomIndex];
            directions[randomIndex] = temp;
        }

        // 访问相邻的Cell
        for (int i = 0; i < 4; i++) {
            int dx = 0;
            int dy = 0;

            switch (directions[i]) {
                case 0:  // 上
                    dy = -1;
                    break;
                case 1:  // 右
                    dx = 1;
                    break;
                case 2:  // 下
                    dy = 1;
                    break;
                case 3:  // 左
                    dx = -1;
                    break;
            }

            int nx = x + (dx * 2);  // 计算下一个位置的x坐标
            int ny = y + (dy * 2);  // 计算下一个位置的y坐标

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[nx][ny].type == Cell::WALL) {
                maze[nx][ny].type = Cell::PATH;  // 更新下一个位置为路径
                maze[nx][ny].x = nx;  // 更新下一个位置的x坐标
                maze[nx][ny].y = ny;  // 更新下一个位置的y坐标
                maze[x + dx][y + dy].type = Cell::PATH;  // 更新当前位置与下一个位置之间的Cell为路径
                stack.push(maze[nx][ny]);  // 将下一个位置的Cell推入栈中
            }
        }
    }
}

void printMaze(const Cell maze[WIDTH][HEIGHT]) {
    for (int y = -1; y < HEIGHT + 1; y++) {
        for (int x = -1; x < WIDTH + 1; x++) {
            if (x == -1 || x == WIDTH || y == -1 || y == HEIGHT) {
                cout << "██";
            } else {
                switch (maze[x][y].type) {
                    case Cell::WALL:
                        cout << "██";
                        break;
                    case Cell::PATH:
                        cout << "  ";
                        break;
                    case Cell::START:
                        cout << "S ";
                        break;
                    case Cell::END:
                        cout << "E ";
                        break;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));
    Cell maze[WIDTH][HEIGHT];

    // 初始化迷宫为墙
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Cell wall = {x, y, Cell::WALL};  // 创建墙的Cell对象
            maze[x][y] = wall;  // 将墙的Cell放入迷宫数组中
        }
    }

    int startX = 1;
    int startY = 1;
    int endX = WIDTH - 2;
    int endY = HEIGHT - 2;

    generateMaze(maze, startX, startY, endX, endY);  // 生成迷宫
    printMaze(maze);  // 打印迷宫


    return 0;
}

const int WIDTH = 22;
const int HEIGHT = 10;

class Cell {
public:
    int x;
    int y;
    int type;

    static const int WALL = 0;
    static const int PATH = 1;
    static const int START = 2;
    static const int END = 3;
};

void generateMaze(Cell maze[WIDTH][HEIGHT], int startX, int startY, int endX, int endY) {
    stack<Cell> stack;
    Cell startCell = {startX, startY, Cell::START};
    Cell endCell = {endX, endY, Cell::END};

    maze[startX][startY] = startCell;
    maze[endX][endY] = endCell;
    stack.push(startCell);

    while (!stack.empty()) {
        Cell current = stack.top();
        int x = current.x;
        int y = current.y;
        stack.pop();

        if (x == endX && y == endY) {
            break;
        }

        // Generate random directions
        int directions[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int randomIndex = rand() % 4;
            int temp = directions[i];
            directions[i] = directions[randomIndex];
            directions[randomIndex] = temp;
        }

        // Visit neighboring cells
        for (int i = 0; i < 4; i++) {
            int dx = 0;
            int dy = 0;

            switch (directions[i]) {
                case 0: // Up
                    dy = -1;
                    break;
                case 1: // Right
                    dx = 1;
                    break;
                case 2: // Down
                    dy = 1;
                    break;
                case 3: // Left
                    dx = -1;
                    break;
            }

            int nx = x + (dx * 2);
            int ny = y + (dy * 2);

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[nx][ny].type == Cell::WALL) {
                maze[nx][ny].type = Cell::PATH;
                maze[nx][ny].x = nx;  // Update the x coordinate of the next position
                maze[nx][ny].y = ny;  // Update the y coordinate of the next position
                maze[x + dx][y + dy].type = Cell::PATH;
                stack.push(maze[nx][ny]);
            }
        }
    }
}

void printMaze(const Cell maze[WIDTH][HEIGHT]) {
    for (int y = -1; y < HEIGHT + 1; y++) {
        for (int x = -1; x < WIDTH + 1; x++) {
            if (x == -1 || x == WIDTH || y == -1 || y == HEIGHT) {
                cout << "██";
            } else {
                switch (maze[x][y].type) {
                    case Cell::WALL:
                        cout << "██";
                        break;
                    case Cell::PATH:
                        cout << "  ";
                        break;
                    case Cell::START:
                        cout << "S ";
                        break;
                    case Cell::END:
                        cout << "E ";
                        break;
                }
            }
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));
    Cell maze[WIDTH][HEIGHT];

    // Initialize maze with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Cell wall = {x, y, Cell::WALL};
            maze[x][y] = wall;
        }
    }

    int startX = 1;
    int startY = 1;
    int endX = WIDTH - 2;
    int endY = HEIGHT - 2;

    generateMaze(maze, startX, startY, endX, endY);
    printMaze(maze);


    return 0;
}
