//1344. 时钟指针的夹角
class Solution {
public:
    double angleClock(int hour, int minutes) {
        //1计算分钟与12成的夹角
        double o1=minutes*1.0/60*360;
        //2计算时针与12成的夹角
        hour%=12;
        double o2=hour*1.0/12*360;
        double o3=minutes*1.0/60*5*6;
        double ans=abs(o1-o2-o3);
        return ans<=180?ans:(360-ans);
    }
};
