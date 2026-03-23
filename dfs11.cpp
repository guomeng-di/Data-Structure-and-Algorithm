//98378. 数字接龙
//复杂程度:100%
#include <bits/stdc++.h>
using namespace std;
const int N=11;
int n,k;
int g[N][N],st[N][N],line[N][N][N][N];
int fangxiang[8][2]={{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
bool is_obstacle(int x,int y){
    if(x<1||y<1||x>n||y>n||st[x][y]) return 1;
    return 0;
}
void dfs(int x,int y,vector<int> vec){
    if(x==n&&y==n){
        if(vec.size()!=n*n-1) return ;
        for(auto it:vec) cout<<it;
        exit(0);//从最小的字典序开始，故找到一个就退出
    }
    for(int i=0;i<8;i++){
        int nx=x+fangxiang[i][0];
        int ny=y+fangxiang[i][1];
        if(is_obstacle(nx,ny)) continue;
        if((g[x][y]+1)%k!=g[nx][ny]) continue;
    if(i==1&&(line[x-1][y][x][y+1]||line[x][y+1][x-1][y])) continue;
    if(i==3&&(line[x][y+1][x+1][y]||line[x+1][y][x][y+1])) continue;
    if(i==5&&(line[x][y-1][x+1][y]||line[x+1][y][x][y-1])) continue;    
    if(i==7&&(line[x-1][y][x][y-1]||line[x][y-1][x-1][y])) continue ;
    vec.push_back(i);
    if(abs(fangxiang[i][0])+abs(fangxiang[i][1])==2)
      line[x][y][nx][ny]=1;
    st[nx][ny]=1;
    dfs(nx,ny,vec);
    vec.pop_back();//回溯,恢复状态,撤销刚才的标记
    if(abs(fangxiang[i][0])+abs(fangxiang[i][1])==2)
      line[x][y][nx][ny]=0;//对角线移动
    st[nx][ny]=0;
    }
}
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      cin>>g[i][j];
     vector<int> vec;
     st[1][1]=1;
     dfs(1,1,vec);
     cout<<-1;
    return 0;
}