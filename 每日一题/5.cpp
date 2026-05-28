//2784. 检查数组是否是好的
class Solution {
public:
    bool isGood(vector<int>& nums) {
        //1 示例4的提示给了一些启发
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]+1!=nums.size()) return 0;
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return 0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]!=i+1) return 0;
        }

        return 1;
    }
};
