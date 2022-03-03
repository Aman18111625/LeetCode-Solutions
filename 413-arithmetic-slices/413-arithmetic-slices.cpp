class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int res=0;
        int p=0;
        for(int i=2;i<n;i++){
          if(nums[i-1]-nums[i-2]==nums[i]-nums[i-1]) p++;
          else p=0;
          res+=p;
        }
      return res;
    }
};