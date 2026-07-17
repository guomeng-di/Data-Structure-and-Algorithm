//1967. 作为子字符串出现在单词中的字符串数目
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(int i=0;i<patterns.size();i++){
            if(word.find(patterns[i])!=string::npos) ans++;
        }
        return ans;
    }
};
