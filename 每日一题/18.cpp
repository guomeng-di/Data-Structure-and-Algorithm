//2833. 距离原点最远的点
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int l=0,r=0,m=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L') l++;
            else if(moves[i]=='R') r++;
            else m++; 
        }
        int max_=(l>r?l:r);
        int min_=(l>r?r:l);
        return max_+m-min_;
    }
};
