//44892. 分巧克力
#include <bits/stdc++.h>
using namespace std;
int N,K;
const int n=1e5+3;
int H[n];
int W[n];
int check(int x){
    int sum=0;
    for(int i=1;i<=N;i++){
        sum+=(H[i]/x)*(W[i]/x);
    }return sum;
}
int main() {
    cin>>N>>K;
    for(int i=1;i<=N;i++)scanf("%d %d",&H[i],&W[i]);
    int l=1,r=n;
    while(l<r){
        int mid=l+(r-l+1)/2;
        if(check(mid)>=K) l=mid;
        else r=mid-1;
    }cout<<r;
    return 0;
}