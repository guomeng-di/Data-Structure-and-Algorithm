//48374. 小蓝的括号串1
//法一:栈
#include <bits/stdc++.h>
using namespace std;
int len;
string s;
stack<int> stk;
int main() {
    cin>>len;
    cin>>s;
    for(int i=0;i<len;i++){
        if(s[i]=='(')
            stk.push(1);
        else{
            if(stk.empty()){
                cout<<"No";
                return 0;
            }else
                stk.pop();
        }
    }
    if(stk.empty()) cout<<"Yes";
    else cout<<"No";
    return 0;
}
//法二:前缀和
#include <bits/stdc++.h>
using namespace std;
int len;
char c;
int arr[105];
int sum[105];
int main() {
    cin>>len;
    for(int i=0;i<len;i++){
        cin>>c;
        if(c=='(') arr[i]=1;
        else arr[i]=-1;
    }
    sum[0]=0;
    for(int i=1;i<=len;i++){
        sum[i]=sum[i-1]+arr[i-1];
        if(sum[i]<0){
            cout<<"No";
            return 0;
        }
    }
    if(sum[len]!=0){
            cout<<"No";
            return 0;        
    }else cout<<"Yes";
    return 0;
}
