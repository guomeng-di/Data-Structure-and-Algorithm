//1732. 找到最高海拔
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>sum(gain.size()+1,0);
        for(int i=0;i<gain.size();i++){
            sum[i+1]=sum[i]+gain[i];
        }
        sort(sum.begin(),sum.end());
        return sum[sum.size()-1];
    }
};
