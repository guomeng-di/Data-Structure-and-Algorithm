//3689. 最大子数组总值 I
//1nums.end(),nums.begin()代表的是元素个数
//2 int相乘得long long 时,用1LL*
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans;
        sort(nums.begin(),nums.end());
        //ans=k*(nums.end()-nums.begin());
        //nums.end(),nums.begin()代表的是元素个数
        ans=1LL*k*(nums[nums.size()-1]-nums[0]);
        return ans;
    }
};
