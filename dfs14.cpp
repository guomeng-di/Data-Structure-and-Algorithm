//79. 单词搜索
class Solution {
private:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1}; 
    int st[7][7];
    int ans;
public:
    void dfs(int x,int y,vector<vector<char>>& board, string word,int tar){
        if(tar==word.size()){ans=1;return;}
        if(ans) return;
        for(int i=0;i<4;i++){
            int nx=dx[i]+x,ny=dy[i]+y;
            if(nx<0||nx>=board.size()||ny<0||ny>=board[0].size()){
                continue;
           }if(st[nx][ny]==1||board[nx][ny]!=word[tar]) continue;
           st[nx][ny]=1;
           dfs(nx,ny,board,word,tar+1);
           st[nx][ny]=0;//回溯
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();//行
        int m=board[0].size();//列
        memset(st, 0, sizeof(st)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    st[i][j]=1;
                    dfs(i,j,board,word,1);
                    st[i][j]=0;//回溯
                    if(ans==1) return true;
                }
            }
        }return false;
    }
};