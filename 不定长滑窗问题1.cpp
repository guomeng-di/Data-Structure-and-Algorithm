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
//优化:
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        //枚举最大值,寻找该最大值对应的最小值位置
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            while(1LL*nums[left]*k<nums[right]){
                left++;
            }ans=max(ans,right-left+1);
        }return (nums.size()-ans);
    }
};
//5
//1208. 尽可能使字符串相等
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0;
        int ans=0;
        for(int right=0;right<t.size();right++){
            maxCost-=abs(s[right]-t[right]);
            while(maxCost<0&&left<=right){
                maxCost+=abs(s[left]-t[left]);
                left++;
            }ans=max(ans,right-left+1);
        }return ans;
    }
};