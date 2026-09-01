//3069. 将元素分配到两个数组中 I
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        int curr1=nums[0];
        arr2.push_back(nums[1]);
        int curr2=nums[1];
        for(int i=2;i<nums.size();i++){
            if(curr1>curr2){
                arr1.push_back(nums[i]);
                curr1=nums[i];
            }else{
                arr2.push_back(nums[i]);
                curr2=nums[i];
            }
        }

        for(int i=0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};
