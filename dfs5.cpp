//P1149 [NOIP 2008 提高组] 火柴棒等式
//法一:暴力枚举-->注意i和j的截止数设置
//a+b=c
//a b c的火柴和 = n-4
#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;//记方案数
int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int huo(int x){
    if(x==0) return 6;
    int ans=0;
    while(x){
        ans+=arr[x%10];
        x/=10;
    }return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            int c=i+j;
            if(huo(i)+huo(j)+huo(c)==n-4) cnt++;
        }
    }cout<<cnt;
    return 0;
}
//法二:dfs
//考 全排列 把每个数都试一下
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans[3];//每次的组合
int cnt;
int huo(int x){
    if(x==0) return 6;
    int ans1=0;
    while(x){
        ans1+=arr[x%10];
        x/=10;
    }return ans1;
}
void dfs(int x,int sum){
    if(sum>n-4) return ;
    if(x==3){
        if(sum==n-4&&ans[0]+ans[1]==ans[2]) cnt++;
        return ;
    }
    for(int i=0;i<1000;i++){
        ans[x]=i;
        dfs(x+1,huo(i)+sum);
    }
}
int main(){
    cin>>n;
    dfs(0,0);//位置 火柴数和
    cout<<cnt;
    return 0;
}