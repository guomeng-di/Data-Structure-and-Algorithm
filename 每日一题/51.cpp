//3345. 最小可整除数位乘积 I
class Solution {
public:
int chengji(int num){
    int ans=1;
    while(num){
        ans*=num%10;
        num/=10;
    }
    return ans;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;;i++){
            if(chengji(i)%t==0) return i;
        }
        return 0;
    }
};
