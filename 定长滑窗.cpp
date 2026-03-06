//定长滑窗问题
//入-更新-出
// 定长滑窗套路

// 窗口右端点在 i 时，由于窗口长度为 k，所以窗口左端点为 i−k+1。

// 我总结成三步：入-更新-出。

// 入：下标为 i 的元素进入窗口，更新相关统计量。如果窗口左端点 i−k+1<0，则尚未形成第一个窗口，重复第一步。
// 更新：更新答案。一般是更新最大值/最小值。
// 出：下标为 i−k+1 的元素离开窗口，更新相关统计量，为下一个循环做准备。
// 以上三步适用于所有定长滑窗题目。

//实战:
//1
//1456. 定长子串中元音的最大数目
class Solution {
public:
    int maxVowels(string s, int k) {
        int yuanyin=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
             yuanyin++;
            int left=i-k+1;
            if(left<0) continue;
            ans=max(ans,yuanyin);
            char out=s[left];
            if(out=='a'||out=='e'||out=='i'||out=='o'||out=='u')
             yuanyin--;
        }return ans;
    }
};
//2
//643. 子数组最大平均数 I
//INFINITY正无穷 infinity（发音：/ɪnˈfɪnəti/）
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum=0;
        double average=-INFINITY;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        
        int left=i-k+1;
        if(left<0) continue;
        average=max(average,1.0*sum/k);
         sum-=nums[left];
        }return average;
    }
};
//3
//1343. 大小为 K 且平均值大于等于阈值的子数组数目
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0;
        long long sum=0;
        long long actual=threshold*k;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int left=i-k+1;
            if(left<0) continue;
            if(sum>=actual) cnt++;
            sum-=arr[left];
        }return cnt;
    }
};
//4
//2090. 半径为 k 的子数组平均值
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> f(nums.size(),-1);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];//入
            int left=i-(2*k+1)+1;
            if(left<0) continue;
            f[i-k]=sum/(2*k+1);//更新
            sum-=nums[left];//出
        }return f;
    }
};
