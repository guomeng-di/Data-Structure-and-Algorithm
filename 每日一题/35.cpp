//1688. 比赛中的配对次数
class Solution {
public:
    int numberOfMatches(int n) {
        //法一:假装你是天才
        //每淘汰一支队伍就要进行一次比赛,最后胜出1支队伍,故比赛n-1次
        //return n-1;

        //法二:数据很小,暴力
        int sum=0;
        while(n>1){
            if(n%2==0){
                sum+=(n/2);
                n/=2;
            }else{
                sum+=(n-1)/2;
                n=(n-1)/2+1;
            }
        }
        return sum;
    }
};
