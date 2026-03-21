//P1605 迷宫
//迷宫问题
// * #
// . *
#include <bits/stdc++.h>
using namespace std;
int N,M,T;//长,宽,障碍总数
int sx,sy,fx,fy;//起点坐标,终点坐标
int zhangai_x[12];
int zhangai_y[12];
int st[12][12];
int ans;
int dx[]={0,0,-1,1};//行的变化:右,左,上,下
int dy[]={1,-1,0,0};
bool is_obstacle(int xx,int yy){
    for(int i=1;i<=T;i++){
        if(zhangai_x[i]==xx&&zhangai_y[i]==yy)
            return 1;
    }return 0;
}
void dfs(int x,int y){
    if(x==fx&&y==fy) {ans++;return ;}
    for(int i=0;i<4;i++){
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        if(xx<1||xx>N||yy<1||yy>M) continue;
        if(is_obstacle(xx,yy)) continue;
        if(st[xx][yy]==1) continue;
        else{
            st[xx][yy]=1;
            dfs(xx,yy);
            st[xx][yy]=0;
        }
        
    }
}
int main(){
    cin>>N>>M>>T;
    cin>>sx>>sy>>fx>>fy;
    for(int i=1;i<=T;i++) cin>>zhangai_x[i]>>zhangai_y[i];
    st[sx][sy]=1;
    dfs(sx,sy);//起点
    cout<<ans;
    return 0;
}