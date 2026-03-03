//49357. 仙境诅咒
#include <bits/stdc++.h>
using namespace std;
int N;
int x[1003];
int y[1003];
int D;
bool st[1003];//状态数组 0没被诅咒 1被诅咒
void dfs(int current){//current是当前诅咒的
    for(int i=1;i<=N;i++){//遍历
        if(!st[i]){//没有被诅咒
            double s=sqrt((x[current]-x[i])*(x[current]-x[i])+(y[current]-y[i])*(y[current]-y[i]));
            if(s<=D){
                st[i]=1;
                dfs(i);//代替current
            }
        }
    }
}
int main() {
    cin>>N;
    for(int i=1;i<=N;i++) cin>>x[i]>>y[i];
    cin>>D;
    st[1]=1;
    dfs(1);//从第一个人开始
    for(int i=1;i<=N;i++){
            cout<<st[i]<<endl;
    }
    return 0;
}