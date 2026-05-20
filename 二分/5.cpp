//49099. 小蓝吃糖果(线性筛 贪心 排序 前缀和 二分)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
vector<int> arr;
const int N=1e5+3;
ll sum[N];
int main() {
    cin>>n>>q;
    int aa;
    for(int i=0;i<n;i++){
        scanf("%d",&aa);
        arr.push_back(aa);
    }
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    sum[0]=arr[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    while(q--){
        ll x; scanf("%lld",&x);
        int l=0,r=n-1;
        int ans=-2;
        while(l<=r){
        int mid=l+(r-l)/2;
        if(sum[mid]==x) {ans=mid;break;}
        else if(sum[mid]>x){ans=mid;r=mid-1;}//向左
        else l=mid+1;//向右
    }
         cout<<(ans+1)<<endl;
    }
    return 0;
}
// 4 3 2 1
// 0 1 2 3
// 4 7 9 10
