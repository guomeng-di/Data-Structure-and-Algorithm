//P1332 血色先锋队
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
const int N=510;
int dist[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
queue<pair<int,int>> q;
void bfs(int x,int y){
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
        int nx=t.first+dx[i],ny=t.second+dy[i];
        if(nx<1||ny<1||nx>n||ny>m) continue;
        if(dist[nx][ny]!=-1) continue;
        q.push({nx,ny});
        dist[nx][ny]=dist[t.first][t.second]+1;
        }
    }return ;
}
int main(){
    cin>>n>>m>>a>>b;
    memset(dist,-1,sizeof(dist));
    int x,y;
    for(int i=0;i<a;i++){
        cin>>x>>y;
        q.push({x,y});
        dist[x][y]=0;
    }
    bfs(x,y);
    for(int i=0;i<b;i++){
        cin>>x>>y;
        cout<<dist[x][y]<<endl;
    }
    return 0;
}