class NumArray {
   vector<int>prefix;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefix.clear();
        prefix.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
          prefix.push_back(prefix[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
          if(left==0) return prefix[right];
        return prefix[right]-prefix[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */