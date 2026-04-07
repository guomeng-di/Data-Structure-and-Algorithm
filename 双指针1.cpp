//167. 两数之和 II - 输入有序数组
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int r=numbers.size()-1,l=0;//下标
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                ans[0]=l+1,ans[1]=r+1;
                return ans;
            }else if(numbers[l]+numbers[r]<target) l++;
            else r--;
        }
        return ans;
    }
};