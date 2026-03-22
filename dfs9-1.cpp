//P1605 迷宫
//地图 求符合要求路线数
#include <bits/stdc++.h>
using namespace std;
int N,M,T;//长宽和障碍总数
int sx,sy,fx,fy;//起点终点坐标
//障碍点的坐标
int zhangai_x[7];
int zhangai_y[7];
bool st[6][6];//状态
int ans;
//控制移动
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool is_obstacle(int x,int y){
    for(int i=1;i<=T;i++){
        if(zhangai_x[i]==x&&zhangai_y[i]==y){
            return 1;
        }
    }return 0;
}
void dfs(int x,int y){
    if(x==fx&&y==fy){ans++;return;}
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1||nx>N||ny<1||ny>M) continue;
        if(st[nx][ny]==1) continue;
        if(is_obstacle(nx,ny)) continue;
        st[nx][ny]=1;
        dfs(nx,ny);
        st[nx][ny]=0;
    }
}
int main(){
    cin>>N>>M>>T;
    cin>>sx>>sy>>fx>>fy;
    for(int i=1;i<=T;i++) cin>>zhangai_x[i]>>zhangai_y[i];
    st[sx][sy]=1;
    dfs(sx,sy);
    cout<<ans;
}