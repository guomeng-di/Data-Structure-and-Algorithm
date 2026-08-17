//1200. 最小绝对差
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        //1排序
        sort(arr.begin(),arr.end());
        //2计算差
        int min_=INT_MAX;
        vector<int> diff(arr.size()-1);
        for(int i=1;i<arr.size();i++){
            diff[i-1]=abs(arr[i]-arr[i-1]);
            min_=min(min_,diff[i-1]);
        }
        //3查找
        for(int i=0;i<diff.size();i++){
            if(min_==diff[i])
            ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};
