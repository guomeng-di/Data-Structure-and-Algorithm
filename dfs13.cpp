//P1025 [NOIP 2001 提高组] 数的划分
#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int arr[205];
void dfs(int x,int start){
    if(x>k){
        long long sum=0;
        for(int i=1;i<=k;i++) sum+=arr[i];
        if(sum>n) return ;
        if(sum==n) ans++;
        return ;
    }
    for(int i=start;i<n;i++){
        arr[x]=i;
        dfs(x+1,i);
        arr[x]=0;
    }
}
int main(){
    cin>>n>>k;
    dfs(1,1);//位置 start sum
    cout<<ans;
    return 0;
}