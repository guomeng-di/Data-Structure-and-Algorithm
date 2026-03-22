//P1683 入门
//地图 重复走不计数 最优
#include <bits/stdc++.h>
using namespace std;
int W,H;//列 行
const int N=25;
char g[N][N];//地图
int st[N][N];//状态
//移动的实现
int dx[]={-1,0,1,0};//上 右 下 左
int dy[]={0,1,0,-1};
int cnt=1;
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(nx<0||nx>=H||ny<0||ny>=W) continue;//出界
        if(st[nx][ny]==1||g[nx][ny]=='#') continue;
        st[nx][ny]=1;
        cnt++;
        dfs(nx,ny);
    }
}
int main(){
    cin>>W>>H;
    for(int i=0;i<=H;i++)
        scanf("%s",g[i]);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(g[i][j]=='@'){
                st[i][j]=1;
                dfs(i,j);//坐标
                break;
            }
        }
    }cout<<cnt;
    return 0;
}