//628. 三个数的最大乘积
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int ans1=nums[0]*nums[1]*nums[2];
        if(ans1>0){
            if(nums[nums.size()-1]>0) return ans1;
            else if(nums[nums.size()-2]>0) return ans1;
            else{
                ans1=max(ans1,nums[nums.size()-1]*nums[nums.size()-2]*nums[0]);
                return ans1;
            }
        }else if(ans1==0){
            return max(0,nums[nums.size()-1]*nums[nums.size()-2]*nums[0]);
        }
        else{
            if(nums[1]>0&&nums[2]<0) return max(ans1,nums[nums.size()-1]*nums[nums.size()-2]*nums[0]);
            else if(nums[0]>0&&nums[1]<0) return nums[nums.size()-1]*nums[nums.size()-2]*nums[0];
            else{
return ans1;
            }
//20 10 -2 -7 -8
        }
        }
};//3 2 1
//3 2 -1
//3 -1 -2 -3 -4
//-1 -2 -3
