//3783. 整数的镜像距离
class Solution {
public:
    int mirrorDistance(int n) {
        //1翻转
        string s=to_string(n);
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            cnt=(s[i]-'0')+cnt*10;
        }
        //2比较
        return abs(cnt-n);
    }
};
