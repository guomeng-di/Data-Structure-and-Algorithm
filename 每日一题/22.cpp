//1848. 到目标元素的最小距离
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left=start-1,right=start+1;
        while(1){
            if(nums[start]==target) return 0;
            else if(left>=0&&nums[left]==target) return(start-left);
            else if(right<nums.size()&&nums[right]==target) return(right-start);
            else{
                left--,right++;
            }
        }
    }
};
