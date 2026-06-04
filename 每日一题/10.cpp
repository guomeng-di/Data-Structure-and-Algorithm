class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            vector<int> arr;
            int j=i;
            while(j){
                arr.push_back(j%10);
                j/=10;
            }//120 arr:0 2 1
            if(arr.size()<3) continue;
            for(int q=1;q<arr.size()-1;q++){
                if(arr[q-1]<arr[q]&&arr[q]>arr[q+1]) ans++;
                else if(arr[q-1]>arr[q]&&arr[q]<arr[q+1]) ans++;
            }
        }
        return ans;
    }
};
