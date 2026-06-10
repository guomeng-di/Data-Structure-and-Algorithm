//788. 旋转数字
class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int c=i;
            int sum=0;
            int d=i;
            while(d){
                int q=d%10;
                if(d%10==3||q==4||q==7){
                    goto a;
                }
                d/=10;
            }
            while(c){
                int q=c%10;
                if(q==2||q==5||q==6||q==9){
                    ans++;
                    break;
                }
                c/=10;
            }
            a:
        }
        return ans;
    }
};
