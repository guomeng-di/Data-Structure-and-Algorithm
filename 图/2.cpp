//1791. 找出星型图的中心节点
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;//有n个数
        vector<int> arr(n+1,0);
        for(int i=0;i<n-1;i++){
            arr[edges[i][0]]++;
            arr[edges[i][1]]++;
        }
        int idex=1;
        for(int i=1;i<=n;i++){
            if(arr[idex]<arr[i]) idex=i;
        }
        return idex;
    }
};
