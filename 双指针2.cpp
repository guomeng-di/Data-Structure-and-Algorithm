//43831. 珠心算测验
//法一:因数据范围小,直接暴力
//1.注意读题!问题是"有多少个数，恰好等于集合中另外两个（不同的）数之和"
//倘若 1 2 3 4 5 
//对于5,1+4=5,2+3=5,5记入一而非二!!
//2.sort排序
#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
vector<int> arr;
int st[103];
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(st[k]==0&&arr[i]+arr[j]==arr[k])
                  {ans++;st[k]=1;}
                else if(arr[i]+arr[j]<arr[k]) 
                  break;
            }
        }
    }
cout<<ans;
    return 0;
}
//法二:两层循环->借助双指针实现
//对target遍历,对a1,a2利用指针
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
int ans;
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<=n;i++){
        int l=0,r=i-1;//下标
        while(l<r){
            if(l<r&&arr[l]+arr[r]==arr[i]){
                ans++;
                break;
            }else if(l<r&&arr[l]+arr[r]<arr[i]){
                l++;
            }else if(l<r&&arr[l]+arr[r]>arr[i]){
                r--;
            }else break;
        }
    }
    cout<<ans;
    return 0;
}