//566. 重塑矩阵
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int r1=mat.size(),l1=mat[0].size();
        if(r1*l1!=r*c) return mat;
        vector<int>A(r1*l1);
        int cnt=0;
        for(int i=0;i<r1;i++){
            for(int j=0;j<l1;j++){
                A[cnt++]=mat[i][j];
            }
        }
        cnt=0;
        vector<vector<int>> ans(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=A[cnt++];
            }
        }
        return ans;
    }
};
