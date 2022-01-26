class Solution {
   bool helper(vector<int>&nums,int n,int sum,vector<vector<int>>&dp){
     if(sum==0) return true;//it means sum is present
     if(n<=0) return false;//we exhausted the given vector
     //if nums[i]>sum then we'll not include it otherwise for every nums[i] we have two options rather we can include it or not
     if(dp[n][sum]!=-1) return dp[n][sum];
     if(nums[n-1]>sum) return dp[n][sum]=helper(nums,n-1,sum,dp);
    return dp[n][sum]=helper(nums,n-1,sum-nums[n-1],dp) || helper(nums,n-1,sum,dp);
   }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto &num : nums) sum+=num;
        if(sum%2) return false;
        sum/=2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(nums,n,sum,dp);
    }
};

 