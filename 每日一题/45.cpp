//3536. 两个数字的最大乘积
class Solution {
public:
    int maxProduct(int n) {
        int a=0,b=0;
        while(n){
            int mod=n%10;
            if(mod>a) {b=a;a=mod;}
            else if(mod>b) b=mod;
            n/=10;
        }
        return a*b;

    }
};
