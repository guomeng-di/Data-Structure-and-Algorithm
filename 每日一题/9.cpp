//2126. 摧毁小行星
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long mass1=(long long)mass;
        for(int i=0;i<asteroids.size();i++){
            if(mass1<asteroids[i]) return 0;
            mass1+=asteroids[i];
        }
        return 1;
    }
};
