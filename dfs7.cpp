//P1135 奇怪的电梯
//dfs暴力 得52分
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