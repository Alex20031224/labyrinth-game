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
