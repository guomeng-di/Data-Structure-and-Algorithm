//1291. 顺次数
class Solution {
    vector<int> ans;
    int low_,high_;
public:
    void dfs(int start,int curr){
        if(curr>high_) return;
        if(curr>=low_) ans.push_back(curr);

        int next=start+1;
        if(next>9) return;
        dfs(next,curr*10+next);
    }
    vector<int> sequentialDigits(int low, int high) {
        ans.clear();
        low_=low,high_=high;
        //i是首位数字(12->1,23->2)
        for(int i=1;i<=9;i++){
            dfs(i,i);//i1是最高位数字,i2是当前这个数的大小
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
//dfs
