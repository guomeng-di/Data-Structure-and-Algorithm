//不定长滑窗问题
//主要分为三类：求最长子数组，求最短子数组，求子数组个数。
//滑动窗口相当于在维护一个队列。右指针的移动可以视作入队，左指针的移动可以视作出队。
//1
//3. 无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[128]={0};//哈希表存字母当前出现次数
        int left=0;int ans=0;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            arr[c]++;
            while(arr[c]>1){
                arr[s[left]]--;
                left++;
            }ans=max(ans,right-left+1);
        }return ans;
    }
};
//2
//3090. 每个字符最多出现两次的最长子字符串
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int arr[128]={0};//哈希
        int left=0;int ans=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            arr[c]++;
            while(arr[c]>2){
                arr[s[left]]--;
                left++;
            }ans=max(ans,i-left+1);
        }return ans;
    }
};
//3
//1493. 删掉一个元素以后全为 1 的最长子数组
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int arr[2]={0};
        int left=0;int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) arr[1]++;
            else arr[0]++;
            while(arr[0]>1){
                arr[nums[left]]--;
                left++;
            }if(arr[0]) ans=max(ans,arr[1]);
            else ans=max(ans,i-left);
        }return (ans>0)?ans:0;
    }
};
//4
//3634. 使数组平衡的最少移除数目
//超时:
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if(nums.size()<=1) return 0;
        int ans=nums.size();
        bool a=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            long long target=(long long)nums[i]*k;
            for(int j=i+1;j<nums.size();j++){
                int cnt=i;
                if(nums[j]>target){ a=1;cnt+=(nums.size()-j);
                ans=min(ans,cnt);
                break;}
                if(j==nums.size()-1) ans=min(ans,cnt);
            }
        }
        if(a==0) return 0;
        return ans;
    }
};
// 1 2 5
// 2 4 10

// 1 2 6  9
// 3 6 18 27
//1 23 34
//2 46 68