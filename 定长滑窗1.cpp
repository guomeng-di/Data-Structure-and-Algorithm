class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int sum=0;
        int ans=0;
        for(int i=0;i<blocks.size();i++){
            if(blocks[i]=='B') sum++;
            int left=(i-k+1);
            if(left<0) continue;
            ans=max(sum,ans);
            if(blocks[left]=='B') sum--;
        }return (ans>k)?0:(k-ans);
    }
};