class Solution {
public:
    //Brute-Force
    //TC:=>O(N^Target)
    //SC:=>O(N)(stack-space)
    // int combinationSum4(vector<int>& nums, int target) {
    //     if(target==0) return 1;
    //     int ans=0;
    //     for(auto &num: nums){
    //      if(num<=target)
    //        ans+=combinationSum4(nums,target-num);
    //     }
    //     return ans;
    // }
  int helper(vector<int>&nums,int target,vector<int>&dp){
    if(target==0) return 1;
    if(dp[target]!=-1) return dp[target];
    dp[target]=0;
    for(auto num: nums){
      if(num<=target)
        dp[target]+=helper(nums,target-num,dp);
    }
    return dp[target];
  }
    
  int combinationSum4(vector<int>& nums, int target) {
    vector<int>dp(target+1,-1);
    return helper(nums,target,dp);
  }
};