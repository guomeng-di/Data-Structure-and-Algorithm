//796. 旋转字符串
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return 0;
        if((s+s).find(goal)!=string::npos) return 1;
        return 0;
    }
};
