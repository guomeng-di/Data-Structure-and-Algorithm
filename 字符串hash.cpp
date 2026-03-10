//45497. 斤斤计较的小Z
//字符串hash
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int base=1331;
const int maxn=1e6+10;
ULL h[maxn],p[maxn];//h是前缀和 p是pow函数的实现
string s1,s2;
int len1,len2;
void calcHash(string& s){
    h[0]=s[0];
    for(int i=1;i<len2;i++){
        h[i]=h[i-1]*base+s[i];
    }
}
void init_pow(){
    p[0]=1;
    for(int i=1;i<maxn;i++){
        p[i]=p[i-1]*base;
    }
}
ULL getHash(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];
}
int main() {
    cin>>s1>>s2;
    len1=s1.size();
    len2=s2.size();
    init_pow();
    if(len1>len2){
        cout<<0;
        return 0;
    }
    //计算s1的哈希值
    ULL hash_s1=0;
    for(char c:s1){
        hash_s1=hash_s1*base+c; 
    }
    //计算s2的前缀哈希
    calcHash(s2);
    //寻找
    int count=0;
    for(int r=0;r<=len2;r++){
        int l=r-len1+1;
        if(l<0) continue;
        ULL hash_s2=getHash(l,r);
        if(hash_s2==hash_s1) count++;
    }
    cout<<count;
    return 0;
}
//思路:
// 先计算模式串 S1 的哈希值
// 用滑动窗口计算 S2 中所有长度为 len (S1) 的子串的哈希值
// 统计 S2 中子串哈希值与 S1 哈希值相等的次数