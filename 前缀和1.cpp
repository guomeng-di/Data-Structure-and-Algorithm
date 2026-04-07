//48869. 小郑的蓝桥平衡串
#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int main() {
    cin>>s;
    int len=s.size();
    a.resize(len+1);
    for(int i=0;i<len;i++){
        if(i==0){
            a[0]=(s[0]=='L')?1:-1;
        }else{
            a[i]=a[i-1]+((s[i]=='L')?1:-1);
        }
    }
    int ans=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(i==0&&a[j]==0) ans=max(ans,j+1);
            else if(a[j]-a[i-1]==0)
              ans=max(ans,j-i+1);
        }
    }
    cout<<ans;
    return 0;
}

//1 0 1 2