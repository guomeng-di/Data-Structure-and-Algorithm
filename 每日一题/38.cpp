//832. 翻转图像
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size(),n=image[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=(image[i][n-1-j]==1?0:1);
            }
        }
        if(n%2){
            for(int i=0;i<m;i++){
                ans[i][n/2]=(image[i][n/2]==1?0:1);
            }
        }
        return ans;
    }
};
