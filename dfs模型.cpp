//92. 递归实现指数型枚举
#include <bits/stdc++.h>
using namespace std;
int n;
int st[16];
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            if(st[i]==1)
               cout<<i<<" ";
        } cout<<endl;
        return ;
    }
    st[x]=1;
    dfs(x+1);
    st[x]=0;
    
    st[x]=2;
    dfs(x+1);
    st[x]=0;
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}
//94. 递归实现排列型枚举
#include <bits/stdc++.h>
using namespace std;
int n;
bool st[10];
int arr[10];
void dfs(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<' ';
        }cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i]=1;
            arr[x]=i;
            dfs(x+1);
            st[i]=0;
            arr[x]=0;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}
//93. 递归实现组合型枚举
#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[27];
void dfs(int x,int start){
    if(x>m){
        for(int i=1;i<=m;i++){
            cout<<arr[i]<<' ';
        }cout<<endl;
        return ;
    }
    for(int i=start;i<=n;i++){
        arr[x]=i;
        dfs(x+1,i+1);
        arr[x]=0;
    }
}
int main(){
    cin>>n>>m;
    dfs(1,1);//1为位置,1为start
    return 0;
}