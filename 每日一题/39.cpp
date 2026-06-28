//3402. 使每一列严格递增的最少操作次数
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();//行数，列数
        int sum=0;
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                if(grid[i][j]>grid[i-1][j]) continue;
                else{
                    sum+=grid[i-1][j]+1-grid[i][j];
                    grid[i][j]=grid[i-1][j]+1;
                }
            }
        }
return sum;
    }
};
