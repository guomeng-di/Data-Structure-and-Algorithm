//48947. 飞机降落
//这道题是在未找到之前,尝试让每一个都作为第一个降落的
#include <bits/stdc++.h>
using namespace std;
int T1;
int N;
int found;
int T[10003];
int D[10003];
int L[10003];
bool st[10003];
void dfs(int curr_time,int cnt){
            if(cnt==N){
            found=1;
            return ;
        }
    for(int i=1;i<=N;i++){
        if(found==1) return ;
        if(!st[i]){
        int earlist_time=T[i];
        int last_time=D[i]+T[i];
        int actuall_time=max(earlist_time,curr_time);
        if(actuall_time<=last_time){
            st[i]=1;
            dfs(actuall_time+L[i],cnt+1);
            st[i]=0;//回溯
        }
        }
    }
}
int main() {
    cin>>T1;
    while(T1--){
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>T[i]>>D[i]>>L[i];
        }
        dfs(0,0);
        if(found)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        found=0;//初始化
        for(int i=1;i<=N;i++) st[i]=0;//初始化
    }
    return 0;
}