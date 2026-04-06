//49406. 妮妮的月饼工厂
#include <bits/stdc++.h>
using namespace std;
int N,K;
const int n=1e5+3;
int arr[n];
int check(int x){
    int sum=0;
    for(int i=1;i<=N;i++)
    sum+=arr[i]/x;
    
    return sum;
}
int main() {
    cin>>N>>K;
    for(int i=1;i<=N;i++) scanf("%d",&arr[i]);
    int l=1,r=1e9,ans=-1;
    while(l<r){
        int mid=l+(r-l+1)/2;
        if(check(mid)>=K) {l=mid;ans=mid;}
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}