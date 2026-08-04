//3731. 找出缺失的元素
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();//一共有4个数
        if(n<=1) return ans;
        sort(nums.begin(),nums.end());
unordered_set<int> mp(nums.begin(),nums.end());//集合去重
        for(int i=nums[0];i<=nums[n-1];i++){
            if(!mp.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
