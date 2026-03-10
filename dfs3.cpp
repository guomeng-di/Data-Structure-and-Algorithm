//洛谷:P2089 烤鸡
//类型:递归实现指数型枚举
//变化:从原来的选不选变成现在的选几个
//因为要先输出cnt 所以用二维数组存下答案
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[11];
int cnt=0;
const int maxn=1000000;
vector<vector<int>> ans(maxn,vector<int>(11));
void dfs(int x,int sum){
    if(x>10){
        if(sum==n){
            cnt++; 
            for(int i=1;i<=10;i++){
                ans[cnt][i]=arr[i];
            }
        }return ;
    }
    sum+=1;
    arr[x]=1;
    dfs(x+1,sum);
    sum-=1;
    arr[x]=0;

    sum+=2;
    arr[x]=2;
    dfs(x+1,sum);
    sum-=2;
    arr[x]=0;

    sum+=3;
    arr[x]=3;
    dfs(x+1,sum);
    sum-=3;
    arr[x]=0;    
}
int main(){
    cin>>n;
    if(n<10||n>30){
        cout<<0;
        return 0;
    }
    dfs(1,0);//1是每一种调料 0是sum
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=10;j++){
            cout<<ans[i][j]<<' ';
        }cout<<endl;
    }
    return 0;
}