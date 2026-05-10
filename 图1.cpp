//997. 找到小镇的法官
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n+1,0);
        vector<int> b(n+1,0);
        int q=trust.size();
        //if(q>=n) return -1;
        for(int i=0;i<q;i++){
            arr[trust[i][1]]++;
            b[trust[i][0]]=1;
        }

        int idex=1;
        for(int i=1;i<=n;i++){
            if(arr[idex]<arr[i]) idex=i;
        } 
        if(arr[idex]==n-1&&b[idex]==0) return idex;
        return -1;
   }
};
