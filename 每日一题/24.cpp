//3612. 用特殊操作处理字符串 I
class Solution {
public:
    string processStr(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z') res+=s[i];
            else if(s[i]=='*'){
                int n=res.size();
                if(n>=1) res.resize(n-1);
            }else if(s[i]=='#'){
                int n=res.size();
                if(n>=1) res+=res;
            }else{
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};
