//P1683 入门
//迷宫问题 重要
#include<bits/stdc++.h>
using namespace std;
const int N = 30;
bool st[N][N];
char road[N][N];
int w,h;//w列 ; h行
int cnt = 1;
//每个点可以往上下左右四个方向移动
int move_x[4] = {-1 , 1 , 0 , 0};
int move_y[4] = {0 , 0 , -1 , 1};

void dfs(int x , int y)
{
    for(int i = 0; i < 4; i++)
    {
        int a = x + move_x[i];
        int b = y + move_y[i];

        if(st[a][b]) continue;//可以走,但是不计数

        if(a>0 && b>0 && a<=h && b<=w && road[a][b]!='#')
        {
            cnt++;
            st[a][b] = true;
            dfs(a , b);
        }
    }
}

int main()
{
    cin>>w>>h;
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            cin>>road[i][j];


    //获取初始时的第一块瓷砖
    int x , y;
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            if(road[i][j] == '@')
            {
                st[i][j] = true;
                dfs(i , j);
            }

    cout<<cnt<<endl;

    return 0;
}
// @ .
// . # 的答案是3,因为可以@->.(2,1)->@->.(1,2);三次