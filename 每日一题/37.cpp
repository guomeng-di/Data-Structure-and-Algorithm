//3185. 构成整天的下标对数目 II
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,long long> mp;
        for(int i=0;i<hours.size();i++){
            mp[hours[i]%24]++;
        }//记录同一条件出现次数
        long long ans=0;
        bool sign1=0;
        bool sign2=0;
        for(int i=0;i<hours.size();i++){
            if(hours[i]%24==0&&sign1==0){
                sign1=1;
                ans+=mp[0]*(mp[0]-1);
            }
            else if(hours[i]%24==12&&sign2==0){
                sign2=1;
                ans+=mp[12]*(mp[12]-1);
            }
            else if(hours[i]%24!=0&&hours[i]%24!=12)
            ans+=mp[24-hours[i]%24];
        }
        return ans/2;
    }
};3185. 构成整天的下标对数目 II
