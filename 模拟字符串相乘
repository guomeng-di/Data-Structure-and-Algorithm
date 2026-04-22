class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int len1=num1.size(),len2=num2.size();
        vector<int> res(len1+len2,0);
        for(int i=len1-1;i>=0;i--){
            int num1_=num1[i]-'0';
            for(int j=len2-1;j>=0;j--){
                int num2_=num2[j]-'0';
                int sum=num1_*num2_+res[i+j+1];
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
            }
        }
        string s;
        for(int i=0;i<res.size();i++){
            if(!(s.empty()&&res[i]==0)) s.push_back(res[i]+'0');
        }
        return s;
    }
};
