//P2249 【深基13.例1】查找
//法一:map映射
#include <bits/stdc++.h>
using namespace std;
int n,m1;//数字个数和询问次数
map<int,int> m;
const int N=1e5+3;
int ask[N];
int main(){
    cin>>n>>m1;
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        if(m[x]==0)
            m[x]=i;
    }
    for(int i=1;i<=m1;i++){
        int y; scanf("%d",&y);
        if(m[y]==0) printf("-1 ");
        else printf("%d ",m[y]);
    }
    return 0;
}
//法二:二分
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6+3;
int arr[N];
const int M=1e5+3;
int ask[M];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=m;i++){ 
        scanf("%d",&ask[i]);
        int l=1,r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]==ask[i]) r=mid;
            else if(arr[mid]>ask[i]) r=mid-1;
            else l=mid+1;
        }
        if(arr[r]==ask[i]) printf("%d ",r);
        else printf("-1 ");
    }
    return 0;
}