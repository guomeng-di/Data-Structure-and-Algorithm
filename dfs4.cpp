//P1088 [NOIP 2004 普及组] 火星人
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+1;
int n;//1-n
int M;
int ans[N];//存答案
int start1[N];//起点
int cnt;//对应m
int st[N];//状态
int flag;//为了避免超时,找到就return dfs,而不是return 上一层
void dfs(int x){
    if(flag) return ;
    if(x>n){
        cnt++;
        if(cnt==M+1){
            for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
        cout<<endl;flag=1;}return ;
    }
    for(int i=1;i<=n;i++){
        if(cnt==0){//从给的数开始找!
            i=start1[x];
        }
        if(!st[i]){
            st[i]=1;
            ans[x]=i;
            dfs(x+1);
            st[i]=0;
            ans[x]=0;
        }
    }
}
int main(){
    cin>>n>>M;
    for(int i=1;i<=n;i++) cin>>start1[i];
    dfs(1);
    return 0;
}