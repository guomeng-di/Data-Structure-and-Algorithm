//P2036 [COCI 2008/2009 #2] PERKET
//每种配料,都考虑选和不选->指数型
//至少一种配料!!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int sour[13];
int ku[13];
const ll a=1e9+1;
ll ans=a;
int st[13];//1选 2不选
void dfs(int x,ll chengji,ll sum){
    if(x>n){
        if(!(chengji==1&&sum==0)){//至少一个
        ll curr=abs(chengji-sum);
        ans=min(ans,curr);}
        return ;
    }
    //选
    dfs(x+1,chengji*sour[x],sum+ku[x]);
    //不选
    dfs(x+1,chengji,sum);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>sour[i]>>ku[i];
    dfs(1,1,0);//数
    cout<<ans;
    return 0;
}