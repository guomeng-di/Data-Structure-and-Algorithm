//8. 字符串转换整数 (atoi)
class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int n=0;
        int m=0;
        int q=0;
        int fuhao=1;
        for(int i=0;i<s.size();i++){
            if(q==0&&n==0&&s[i]==' ') continue;
            else if(q==1&&s[i]==' ') break;
            else if((n==1||m==1)&&(s[i]=='+'||s[i]=='-')){
                break;
            }else if(n==0&&(s[i]=='+'||s[i]=='-')){
                n=1;
                fuhao=s[i]=='+'?1:-1;
            }else if(!(s[i]>='0'&&s[i]<='9')){
                break;
            }else{
                ans=ans*10+(s[i]-'0');
                if((ans>0&&ans>INT_MAX)||(ans<0&&ans<INT_MIN)) break;
                m=1;q=1;
            }
        }
       int ans1=0;
       ans=fuhao*ans;
       if(ans>0) ans1=(ans>INT_MAX?INT_MAX:ans);
       else ans1=(ans<INT_MIN?INT_MIN:ans);
       return ans1;
       }
};
