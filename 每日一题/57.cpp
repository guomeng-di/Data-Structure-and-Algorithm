//3718. 缺失的最小倍数
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int cnt=1;
        while(1){
            auto it=find(nums.begin(),nums.end(),k*cnt);
            if(it==nums.end()){
                return k*cnt;
            }
            cnt++;
        }
            return -1;
    }
};
