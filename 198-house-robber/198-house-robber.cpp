class Solution {
  int dp[101];
  int helper(vector<int>&nums,int idx)
  {
    if(idx<0) return 0;
    if(idx==0) return nums[idx];
    if(dp[idx]!=-1) return dp[idx];
    //now for every we have to option 
    int op1=nums[idx]+helper(nums,idx-2);
    int op2=helper(nums,idx-1);
    return dp[idx]=max(op1,op2);
  }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
       return helper(nums,n-1);
    }
};