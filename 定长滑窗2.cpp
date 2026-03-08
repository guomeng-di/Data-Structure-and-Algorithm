//2841. 几乎唯一子数组的最大和
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans=0;
        long long sum=0;
        unordered_map<int,int>cnt;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            cnt[nums[right]]++;
            int left=right-k+1;
            if(left<0) continue;
            if(cnt.size()>=m) ans=max(ans,sum);//!!
            sum-=nums[left];
            cnt[nums[left]]--;
            if(cnt[nums[left]]==0) cnt.erase(nums[left]);
        }return ans;
    }
};
//本想用前缀和,害怕sum超范围
//改用滑动窗口
//初步:
// class Solution {
// public:
//     long long maxSum(vector<int>& nums, int m, int k) {
//         long long ans=INT_MIN;
//         long long sum=0;
//         for(int right=0;right<nums.size();right++){
//             sum+=nums[right];
//             int left=right-k+1;
//             if(left<0) continue;
//             ans=max(ans,sum);
//             sum-=nums[left];
//         }return ans;
//     }
// };
//至少 m 个互不相同的元素==最多有(k-m)个相同的元素
//哈希表