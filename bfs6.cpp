//P1747 好奇怪的游戏
#include <bits/stdc++.h>
using namespace std;
int x1,yy1,x2,y2;
const int N=25;
int dist[N][N];//到(1,1)的距离
typedef pair<int,int> PII;
queue<PII> q;

// int dx1[]={1,1,-1,-1,2,2,-2,-2};
// int dy1[]={2,-2,1,-1,1,-1,2,-2};//"日"字:(x ± 1, y ± 2) (x ± 2, y ± 1)

// int dx2[]={2,2,-2,-2};
// int dy2[]={2,-2,2,-2};//"田"字:(x ± 2, y ± 2)

int dx[]={1,1,-1,-1,2,2,-2,-2,2,2,-2,-2};
int dy[]={2,-2,1,-1,1,-1,2,-2,2,-2,2,-2};

void bfs(int x,int y){
    q.push({x,y});
    dist[x][y]=0;
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<12;i++){
            int nx=dx[i]+t.first,ny=dy[i]+t.second;
            if(nx<1||ny<1||nx>20||ny>20) continue;
            if(dist[nx][ny]!=-1) continue;
            dist[nx][ny]=dist[t.first][t.second]+1;
            q.push({nx,ny});
        }
    }
    return ;
}
int main(){
    cin>>x1>>yy1>>x2>>y2;
    memset(dist,-1,sizeof(dist));
    bfs(1,1);
    cout<<dist[x1][yy1]<<endl;
    cout<<dist[x2][y2];
    return 0;
}