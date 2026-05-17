//415. 字符串相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        string s;
        //1reverse
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        //2对应位相加
        int left1=0,left2=0;
        int len1=num1.size(),len2=num2.size();
        int yu=0;
        while(left1<len1||left2<len2){
            int sum=(left1<len1?num1[left1++]-'0':0)+(left2<len2?num2[left2++]-'0':0)+yu;
            s+=sum%10+'0';
            yu=sum/10;
        }
        if(yu!=0) s+=yu+'0';
        reverse(s.begin(),s.end());
        return s;
    }
};
