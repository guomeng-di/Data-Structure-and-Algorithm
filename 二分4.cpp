//4. 寻找两个正序数组的中位数
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sum;
        for(int i=0;i<nums1.size();i++) sum.push_back(nums1[i]);
        for(int i=0;i<nums2.size();i++) sum.push_back(nums2[i]);
        //数组:sort(sum,sum+nums1.size()+nums2.size());
        //vector:
        sort(sum.begin(),sum.end());
        int l=0,r=nums1.size()+nums2.size()-1;
        if(r%2==0) return 1.0*sum[(l+r)/2];
        else return 1.0*(sum[(l+r)/2]+sum[(l+r)/2+1])/2;
    }
};