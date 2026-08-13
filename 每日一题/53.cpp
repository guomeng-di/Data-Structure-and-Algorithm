//3627. 中位数之和的最大值
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        int cnt=nums.size();
        nums.erase(nums.begin(),nums.begin()+cnt/3);
        //erase删除:左闭右开
        for(int i=0;i<nums.size();i+=2){
            ans+=nums[i];
        }
        return ans;
    }
};
// 2 1 3 2 1 3
// 0 1 2 3 4 5  (1 1 2 2 3 3)

// 1 3 3->3->
// 1 2 2->2

// 1 1 10 10 10 10
// 1 10 10->
