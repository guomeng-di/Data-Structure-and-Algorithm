//409. 最长回文串
class Solution {
public:
    int longestPalindrome(string s) {
        //ccc的情况
        
        vector<int> arr(26,0);//存26个英文字母出现次数-小写
        vector<int> arr1(26,0);//存26个英文字母-大写
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z') arr[s[i]-'a']++;
            else arr1[s[i]-'A']++;
        }
        bool sign_jishu=0;
        int sum=0;
        for(int i=0;i<26;i++){
            if(arr[i]%2==0) sum+=arr[i];
            else{
                sign_jishu=1;
                sum+=(arr[i]-1);
            }
        }
        for(int i=0;i<26;i++){
            if(arr1[i]%2==0) sum+=arr1[i];
            else{
                sign_jishu=1;
                sum+=(arr1[i]-1);
            }
        }
        sum+=((sign_jishu==1)?1:0);
        return sum;
    }
};
