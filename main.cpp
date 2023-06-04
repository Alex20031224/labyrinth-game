//
//  main.cpp
//  Object-Oriented Programming and Internships 小專題
//
//  Created by Alex on 2023/5/13.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

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
    
int main() {
    
    srand(time(NULL));
    
    int o1 = 0, o2 = 0; //玩家初始位置
    int pX, pY; //玩家位置
    int mX, mY; //移動位置
    int dX=0, dY=0; //終點位置
    int width = 30, height = 30; //地圖長寬
    int vectMaze[width][height]; //地圖
    
    
    while(dX == 0 && dY == 0) //生成終點位置
    {
        dX = rand() % 29;
        dY = rand() % 29;
    }
    
    for(int i=0; i<height; i++) //生成地圖r
    {
        for(int j=0; j<width; j++) 
        {
            vectMaze[i][j] = rand() % 2;
        }
        
    }
    
    for(int i=0; i<height; i++) //輸出地圖
    {
        for(int j=0; j<width; j++)
        {
            if(j==height-1 || j==0)
            {
                if(j==0 && i==0)
                {
                    cout<<"_";
                }
                else if(i==0 && j==height-1)
                {
                    cout<<"_";
                }
                else
                {
                    cout<<"|";
                }
            }
            else if(i==height-1 || i==0)
            {
                cout<<"_";
            }
            else
            {
                cout<<(vectMaze[i][j]==1?"|":"_");
            }
            //cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<<"遊戲開始"<<endl;
    
    while(pX != dX && pY != dY) //
    {
        cout<<"請輸入要移動的位置：";
        cin >>mX >>mY;
        switch(mX)
        {
            case 1:
                mX++;
            case -1:
                mX--;
            case 0:
                mX = mX;
            default:
                cout<<"請重新輸入：";
        }
    }
    
    if(pX == dX && pY == dY)
    {
        cout<<"遊戲結束"<<endl;
    }
    
}
