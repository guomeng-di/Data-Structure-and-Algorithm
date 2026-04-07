//303. 区域和检索 - 数组不可变
class NumArray {
private:
    vector<int> a;
public:
    NumArray(vector<int>& nums) {
        a.resize(nums.size()+1);
        a[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            a[i]=a[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left>=1)return a[right]-a[left-1];
        else return a[right]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */