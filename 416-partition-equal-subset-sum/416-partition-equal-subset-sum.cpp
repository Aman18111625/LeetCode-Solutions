class Solution {
  /*Recursive + Memoization
  //TC:=>O(N*target)
  //SC:=>O(N*target)+O(N)(stack-space)
   bool helper(vector<int>&nums,int n,int sum,vector<vector<int>>&dp){
     if(sum==0) return true;//it means sum is present
     if(n<=0) return false;//we exhausted the given vector
     //if nums[i]>sum then we'll not include it otherwise for every nums[i] we have two options rather we can include it or not
     if(dp[n][sum]!=-1) return dp[n][sum];//already calculated
     if(nums[n-1]>sum) return dp[n][sum]=helper(nums,n-1,sum,dp);//let's say required sum is 2 and nums[i] >2 then it'll never give us our answer if we include it
     //now for every nums[i] we have two choise either we can take it or not take it 
    return dp[n][sum]=helper(nums,n-1,sum-nums[n-1],dp) || helper(nums,n-1,sum,dp);
   }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto &num : nums) sum+=num;
        if(sum%2) return false;
        sum>>=1;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(nums,n,sum,dp);
    }*/
  public:
  
  
  
    bool canPartition(vector<int>& nums){
        int sum=0,n=nums.size();
        if(n==1) return false;
        for(auto &num : nums) sum+=num;
        if(sum&1) return false;
        sum/=2;
        bool dp[n+1][sum+ 1];
      // step 1: initialization
      // same logic as Subset Sum problem 
      for(int i=0; i<n+1; i++)
      {
        dp[i][0] = true;
      }
      for(int j=0; j<sum+1; j++)
     {
        dp[0][j] = false;
     }
    // step 2: recursive code to iterative code
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            if(nums[i-1] <= j)
            {
                dp[i][j] = ((dp[i-1][j - nums[i-1]]) || dp[i-1][j]); 
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
   return dp[n][sum];
    }
};

 