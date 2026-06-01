//2144. 打折购买糖果的最小开销
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int len=cost.size();
        int ans=0;
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int n=1;
        while(n<=len){
            if(n%3!=0)
                ans+=cost[n-1];
                
            n++;
        }
        return ans;

    }
};
