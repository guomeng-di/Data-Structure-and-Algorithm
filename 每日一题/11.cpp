//2574. 左右元素和的差值
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        vector<int> sums((n+1),0);
        for(int i=1;i<=n;i++){
            sums[i]=sums[i-1]+nums[i-1];
        }
        for(int i=0;i<n;i++){
            if(i==n-1) ans.push_back(sums[i]);
            else{
            int ans_=sums[n]-sums[i]*2-nums[i];
            ans_=abs(ans_);
            ans.push_back(ans_);
            }
        }
        return ans;
    }
};
