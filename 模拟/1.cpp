//495. 提莫攻击
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //每次攻击，贡献的中毒时间 = 两次攻击的间隔 VS 中毒时长，取小的那个！
        if(timeSeries.size()==0) return 0;
        int res=duration;
    for(int i=0;i<timeSeries.size()-1;i++){
        int jiange=timeSeries[i+1]-timeSeries[i];
        res+=min(jiange,duration);
    }
    return res;
    }
};
