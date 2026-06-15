//2515. 到目标字符串的最短距离
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {   vector<int> arr;
        for(int i=0;i<words.size();i++){
            if(words[i]==target) arr.push_back(i);
        }// 0 4
        if(arr.size()==0) return -1;
        int ans=abs(startIndex-arr[0]);
        ans=min(ans,(int)(words.size()-abs(startIndex-arr[0])));
        for(int i=1;i<arr.size();i++){
            ans=min(ans,abs(startIndex-arr[i]));
            ans=min(ans,(int)(words.size()-abs(startIndex-arr[i])));
        }
        return ans;
    }
};
