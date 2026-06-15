//3838. 带权单词映射
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            long long sum=0;
            for(int j=0;j<s.size();j++){
                sum+=weights[s[j]-'a'];
                sum%=26;
            }
            sum%=26;
            ans+=(char)('z'-sum);
        }
        return ans;
    }
};
