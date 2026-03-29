//P1746 离开中山路
//注意读地图时,没有空格,用%s读入
#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1010;
char g[N][N];//地图
int x_1,y_1,x_2,y_2;//起点,终点
int dist[N][N];//与起点距离
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};//上 右 下 左
typedef pair<int,int> PII;
queue<PII> q;
void bfs(int x1,int y1){
    memset(dist,-1,sizeof(dist));
    q.push({x1,y1});
    dist[x1][y1]=0;
    while(!q.empty()){
        auto t=q.front();
        q.pop();
    for(int i=0;i<4;i++){
        int a=t.first+dx[i],b=t.second+dy[i];
        if(a<1||b<1||a>n||b>n) continue;
        if(g[a][b]=='1') continue;
        if(dist[a][b]!=-1) continue;
        q.push({a,b});
        dist[a][b]=dist[t.first][t.second]+1;
     }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            scanf("%s",g[i]+1);
    }
    scanf("%d %d %d %d",&x_1,&y_1,&x_2,&y_2);
    bfs(x_1,y_1);
    cout<<dist[x_2][y_2];
    return 0;
}