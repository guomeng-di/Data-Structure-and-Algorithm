//P1135 奇怪的电梯 重做
//dfs
#include <bits/stdc++.h>
using namespace std;
int N,A,B;
int arr[203];//初始
int st[203];//状态
int ans=INT_MAX;
void dfs(int x,int temp){
    if(x<1||x>N||st[x]==1){//选过or不符合要求
       return ;
    }
    if(x==B){
        ans=min(ans,temp);
        return ;
    }
    int up=x+arr[x];//上
    if(up<=N){
        st[x]=1;
        dfs(up,temp+1);
        st[x]=0;
    }
    int down=x-arr[x];//下
    if(down>=1){
        st[x]=1;
        dfs(down,temp+1);
        st[x]=0;
    }
    
}
int main(){
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++) cin>>arr[i];
    dfs(A,0);//当前楼层
    if(ans!=INT_MAX) cout<<ans;
    else cout<<-1;
    return 0;
}
//bfs
#include <bits/stdc++.h>
using namespace std;
int N,A,B;
queue<int> q;
const int n=210;
int g[n];//地图
bool st[n];//状态
int dist[n];//距离
void bfs(int x){
    q.push(x);
    while(!q.empty()){
        auto t=q.front();
        q.pop();
        int uup=g[t]+t,ddown=t-g[t];
        if(!(uup>N||st[uup])){ 
        st[uup]=1;
        q.push(uup);
        dist[uup]=dist[t]+1;}
        if(!(ddown<1||st[ddown])){ 
        st[ddown]=1;
        q.push(ddown);
        dist[ddown]=dist[t]+1; } 
    }return ;
}
int main(){
    cin>>N>>A>>B;
    memset(dist,-1,sizeof(dist));
    for(int i=1;i<=N;i++) cin>>g[i];
    st[A]=1;
    dist[A]=0;
    bfs(A);
    cout<<dist[B];
    return 0;
}