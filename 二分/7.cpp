//349. 两个数组的交集
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end()),sort(nums2.begin(),nums2.end());

        vector<int> arr;
        int start=0;
        for(int i=0;i<nums1.size()&&start<nums2.size();i++){
            if(nums1[i]==nums2[start]){
                arr.push_back(nums1[i]);
                start++;
            }else if(nums1[i]>nums2[start]){
                while(start<nums2.size()&&nums1[i]>nums2[start]) start++;
            }
            //nums2的start移动后,需要在此判断
            //因为有可能nums1的i走到了最后,如果再次循环,不满足循环条件,直接退出了
            if(start<nums2.size()&&nums1[i]==nums2[start]){
                arr.push_back(nums1[i]);
                start++;
            }
        }
        sort(arr.begin(), arr.end());
        auto last = unique(arr.begin(),arr.end());
        arr.erase(last, arr.end());
        return arr;
    }
};
