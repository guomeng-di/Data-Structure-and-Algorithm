//1260. 二维网格迁移
二维->一维->二维
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size(),l=grid[0].size();
        vector<int> arr;
        for(int i=0;i<r;i++){
            for(int j=0;j<l;j++)
              arr.push_back(grid[i][j]);
        }
        vector<vector<int>> ans(r,vector<int>(l,0));
        int start=r*l-k%(r*l);
        for(int i=0;i<r;i++){
            for(int j=0;j<l;j++){
                ans[i][j]=arr[(start++)%(r*l)];
            }
        }
        return ans;
    }
};
