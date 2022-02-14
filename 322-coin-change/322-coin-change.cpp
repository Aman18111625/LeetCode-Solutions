class Solution {
  /*
   //Recursive+ Memoization
  //Time-Complexity:=>O(N*target)
  //Space-Complexity:=>O(N*target)+O(N)(stack-space)
    int helper(vector<int>& coins, int n, int sum,vector<vector<int>>&dp){
	//why INT_MAX-1 => Because later we are adding 1 while returning the value, so if we return INT_MAX here, doing INT_MAX+1 will cross the range of integer.
        if(n<=0) return INT_MAX-1;
        if(sum == 0) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];
		    //Unbounded Knapsack Code
        if(coins[n-1] <= sum) {
            return dp[n][sum]=min(1 + helper(coins, n, sum-coins[n-1],dp), helper(coins, n-1, sum,dp));
        }
         return dp[n][sum]=helper(coins, n-1, sum,dp);
    }
public:
    int coinChange(vector<int>& coins, int sum) {
        int n= coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int res = helper(coins, n, sum,dp);
        return (res==INT_MAX || res == INT_MAX-1) ? -1 : res;
    }*/
  public:
  //Tabulation :=>
  //Time-Complexity:=>O(N*target)
  //Space-Complexity:=>O(N*target)
    int coinChange(vector<int>& coins, int sum) {
        int n= coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
         for(int target=0;target<=sum;target++)
         {
           if(target%coins[0]==0) dp[0][target]=target/coins[0];
           else dp[0][target]=1e9;
         }
        for(int i=1;i<n;i++)
        {
          for(int j=0;j<=sum;j++)
          {
            int notTake=dp[i-1][j];
            int take=INT_MAX;
            if(coins[i]<=j) take=1+dp[i][j-coins[i]];
            dp[i][j]= min(notTake,take);
          }
        }
      if(dp[n-1][sum]>=1e9) return -1;
      return dp[n-1][sum];
    }
};



    

    
    