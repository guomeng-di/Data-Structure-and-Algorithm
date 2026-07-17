//3754. 连接非零数字并乘以其数字和 I
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        long long sum=0;
        while(n){
            int curr=n%10;
            sum+=curr;
            if(curr){
                ans=curr+ans*10;
            }
            n/=10;
        }
        long long ans1;
        while(ans){
            ans1=ans1*10+ans%10;
            ans/=10;
        }
        return ans1*sum;
    }
};
//sum是和
//原始顺序是ans
