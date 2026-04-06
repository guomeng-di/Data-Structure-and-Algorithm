//44737. 求阶乘
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
//K个5
ULL K;
ULL count(ULL x){
    ULL sum=0;
    while(x>0){
       x/=5;
       sum+=x;
    }
    return sum;
}
// count(x) 计算的是：
// 1 × 2 × 3 × … × x 这个数末尾有几个 0
// 计算方法：
// 不断把 x 除以 5，把每次的商加起来
int main() {
    cin>>K;
    ULL l=0,r=K*5,ans=-1;
    while(l<r){
        ULL mid=l+(r-l)/2;
        if(count(mid)==K) {ans=mid;r=mid;}
        else if(count(mid)>K) r=mid;
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}
//2*5=10 2 5的倍数
//10*9*8*7*6*5*4*3*2
//2-> 2个5 5 10
//3-> 3个5 5 10 15
//5 10 15 20 25=5*5