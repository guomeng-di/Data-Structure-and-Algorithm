//字符串
//1字符串中子串查找 find
//2字符串中子串删除 erase
//3字符串中子串插入 insert
#include <bits/stdc++.h>
using namespace std;
int N;
string S;
int main(){
    cin>>N>>S;
    while(N--){
        int x;
        cin>>x;
        if(x==1){
            string s; cin>>s;
            auto it=S.find(s);
            if(it!=string::npos) cout<<it<<endl;
            else cout<<-1<<endl;
        }else if(x==2){
            string s1,s2; cin>>s1>>s2;
            int len1=s1.size(),len2=s2.size();
            auto it=S.find(s1);
            if(it!=string::npos){
                    S.erase(it,len1);
                    S.insert(it,s2);
            }
                cout<<S<<endl;
        }else{
            char c1,c2;string s; cin>>c1>>c2>>s;
            for(int i=0;i<S.size()-1;i++){
                if(S[i]==c1&&S[i+1]==c2){
                    S.insert(i+1,s);
                    i+=s.size();
                }
            }
                cout<<S<<endl;
        }
    }
    return 0;
}