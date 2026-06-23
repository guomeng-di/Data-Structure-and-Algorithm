//3107. 使数组中位数等于 K 的最少操作数
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long ans=0;
        //1排序
        sort(nums.begin(),nums.end());

          int idex=nums.size()/2;//下标
          if(nums[idex]==k) return 0;
          else if(nums[idex]<k){
            for(int i=idex;i<nums.size();i++){
                if(nums[i]>=k) return ans;
                else{
                    ans+=k-nums[i];
                }
            }
          }else{
            for(int i=idex;i>=0;i--){
                if(nums[i]<=k) return ans;
                else{
                    ans+=nums[i]-k;
                }
            }
          }
          return ans;
    }
};
//2 5 5 6 8
