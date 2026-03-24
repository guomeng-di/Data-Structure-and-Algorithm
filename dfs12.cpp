//P1596 [USACO10OCT] Lake Counting S
//迷宫中统计区域问题
#include <bits/stdc++.h>
using namespace std;
int N,M;
char g[103][103];
int st[103][103];
int ans;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y){
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=N||ny<0||ny>=M) continue;
        if(st[nx][ny]||g[nx][ny]=='.') continue;
        st[nx][ny]=1;
        dfs(nx,ny);
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        scanf("%s",g[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(st[i][j]) continue;
            if(g[i][j]=='.') continue;
            st[i][j]=1;
            dfs(i,j);
            ans++;
        }
    }cout<<ans;
    return 0;
}