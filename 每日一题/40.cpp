//1790. 仅执行一次字符串交换能否使两个字符串相等
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int l1=s1.size(),l2=s2.size();
        if(l1!=l2) return 0;
        if(s1==s2) return 1;
        int idex_1=-1,idex_2=-1;//存下标
        int sign=0;//存个数
        for(int i=0;i<l1;i++){
            if(sign==2) break;
            if(sign==1&&s1[i]!=s2[i]){
                sign++;
                idex_2=i;
            }else if(sign==0&&s1[i]!=s2[i]){
                sign++;
                idex_1=i;
            }
        }
        //if(!sign) return 0;
        if(sign==1) return 0;
        swap(s2[idex_1],s2[idex_2]);
        return s1==s2;
    }
};
