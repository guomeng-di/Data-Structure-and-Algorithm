//49106. 肖恩的苹果林
#include <bits/stdc++.h>
using namespace std;
int N,M;//
const int n=1e5+4;
int arr[n];
int check(int dis){
    int ans=1;
    int sign=1;
    for(int i=2;i<=N;i++){
        int next=arr[sign]+dis;
        if(arr[i]>=next) {ans++;sign=i;}
    }return ans;
}
int main() {
    cin>>N>>M;
    for(int i=1;i<=N;i++) scanf("%d",&arr[i]);
    //sort!
    sort(arr+1,arr+N+1);
    int l=1,r=arr[N]-arr[1];
    while(l<r){
        int mid=l+(r-l+1)/2;//不断往右->保证退出循环
        if(check(mid)>=M) l=mid;
        else r=mid-1;//不断往左
    }
    cout<<r;
    return 0;
}