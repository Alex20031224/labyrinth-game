//
//  Maze.cpp
//  Object-Oriented Programming and Internships 小專題
//
//  Created by Alex on 2023/6/6.
//

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

Maze::Maze()
{
    for (int y = 0; y < HEIGHT; y++) //初始化迷宮為牆壁
    {
        for (int x = 0; x < WIDTH; x++)
        {
            maze[x][y] = WALL;
        }
    }

    startX = 1; //設置起點位置
    startY = 1; //設置起點位置
    endX = WIDTH - 2; //設置終點位置
    endY = HEIGHT - 2; //設置終點位置

    generateMaze(startX, startY, endX, endY);
    playerX = startX;
    playerY = startY;
    maze[playerX][playerY] = PLAYER; //放置玩家至起始位置
}

void Maze::generateMaze(int startX, int startY, int endX, int endY) //生成迷宮路徑
{
    stack<pair<int, int>> stack; //儲存待處理的位置
    maze[startX][startY] = START; //在起點的迷宮陣列中標記為起始狀態
    maze[endX][endY] = END; //在終點的迷宮陣列中標記為終點狀態
    stack.push(make_pair(startX, startY)); //做一個pair物件壓入堆疊中

    while (!stack.empty()) //堆疊為空，表示每個位置皆處理過。要確保每個位置都被處理過
    {
        pair<int, int> current = stack.top(); //取得x和y座標
        int x = current.first; //賦值給x座標
        int y = current.second; //賦值給y座標
        stack.pop(); //移除堆疊，表示已處理過

        if (x == endX && y == endY) //檢查是否為終點
        {
            break;
        }

        int directions[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) //將每個元素與隨機位置上的元素進行交換
        {
            int randomIndex = rand() % 4; //隨機打亂directions陣列的順序
            int temp = directions[i];
            directions[i] = directions[randomIndex];
            directions[randomIndex] = temp;
        }

        for (int i = 0; i < 4; i++)
        {
            int dx = 0; //x軸增量
            int dy = 0; //y軸增量

            switch (directions[i])
            {
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

            int nx = x + (dx * 2); //計算新位置的座標
            int ny = y + (dy * 2); //計算新位置的座標

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[nx][ny] == WALL) //檢查牆壁位置是否在迷宮範圍內
            {
                maze[nx][ny] = PATH; //新位置標記為路徑
                maze[x + dx][y + dy] = PATH; //當前位置與新位置之間的牆壁也標記為路徑
                stack.push(make_pair(nx, ny)); //將新位置加入堆疊中
            }
        }
    }
}

void Maze::movePlayer(char direction) //移動玩家
{
    int dx = 0;
    int dy = 0;

    switch (direction)
    {
        case 'w': //上
            dy = -1;
            break;
        case 'a': //左
            dx = -1;
            break;
        case 's': //下
            dy = 1;
            break;
        case 'd': //右
            dx = 1;
            break;
        default: //除錯
            cout << "請輸入正確方向！" << endl;
            return;
    }

    int newX = playerX + dx; //玩家在迷宮的新座標
    int newY = playerY + dy; //玩家在迷宮的新座標

    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newX][newY] != WALL) //偵測是否碰到牆面
    {
        maze[playerX][playerY] = PATH; //玩家位置標記為路徑
        maze[newX][newY] = PLAYER; //新位置標記為玩家
        playerX = newX; //更新玩家位置
        playerY = newY; //更新玩家位置
    }
    else
    {
        cout << "此路不通，請重新移動" << endl;
    }
}

void Maze::print() //輸出
{
    for (int y = -1; y < HEIGHT + 1; y++)
    {
        for (int x = -1; x < WIDTH + 1; x++)
        {
            if (x == -1 || x == WIDTH || y == -1 || y == HEIGHT) //將外圍都設為牆面
            {
                cout << "##";
            }
            else
            {
                switch (maze[x][y]) //輸出地圖、起始位置、終點位置以及玩家位置
                {
                    case WALL:
                        cout << "##";
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

bool Maze::isGameOver() //判定遊戲是否結束
{
    return playerX == endX && playerY == endY;
}
