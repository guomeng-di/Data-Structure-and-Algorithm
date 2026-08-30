//2091. 从数组中移除最大值和最小值
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        //1记录最大值最小值的元素下标
        int len=nums.size();
        int min_=nums[0],max_=nums[0];
        int min_index=0,max_index=0;
        for(int i=1;i<len;i++){
            if(nums[i]<min_){
                min_=nums[i];
                min_index=i;
            }if(nums[i]>max_){
                max_=nums[i];
                max_index=i;
            }
        }
        //从前
        int f1=min_index>max_index?(min_index+1):(max_index+1);
        //从后
        int f2=min_index<max_index?(len-min_index):(len-max_index);
        //一前一后
        int f3=min_index<max_index?(min_index+1+len-max_index):(-min_index+1+len+max_index);
        int ans=f1<f2?f1:f2;
        return ans<f3?ans:f3;
        
    }
};
