//3300. 替换为数位和以后的最小元素
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            while(nums[i]){
                sum+=nums[i]%10;
                nums[i]/=10;
            }
        ans=min(ans,sum);
        }
        return ans;
    }
};
