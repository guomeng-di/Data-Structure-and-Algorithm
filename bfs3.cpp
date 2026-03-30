//P1443 马的遍历
#include <bits/stdc++.h>
using namespace std;
const int N=410;
int n,m,x,y;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
int dist[N][N];//距离
queue<pair<int,int>> q;//坐标
void bfs(int x,int y){
    memset(dist,-1,sizeof(dist));
    q.push({x,y});
    dist[x][y]=0;
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx=t.first+dx[i],ny=t.second+dy[i];
            if(nx<1||ny<1||nx>n||ny>m) continue;
            if(dist[nx][ny]!=-1) continue;
            q.push({nx,ny});
            dist[nx][ny]=dist[t.first][t.second]+1;
        }
    }return ;
}
int main(){
    cin>>n>>m>>x>>y;
    bfs(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",dist[i][j]);
        }cout<<endl;
    }
    return 0;
}