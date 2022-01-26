class Solution {
 
    int helper(vector<int>& coins, int n, int sum,vector<vector<int>>&dp){
	//why INT_MAX-1 => Because later we are adding 1 while returning the value, so if we return INT_MAX here, doing INT_MAX+1 will cross the range of integer.
        if(n<=0) return INT_MAX-1;
        if(sum == 0) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];
		//Unbounded Knapsack Code
        if(coins[n-1] <= sum) {
            return dp[n][sum]=min(1 + helper(coins, n, sum-coins[n-1],dp), helper(coins, n-1, sum,dp));
        }
        else return dp[n][sum]=helper(coins, n-1, sum,dp);
    }
public:
    int coinChange(vector<int>& coins, int sum) {
        int n= coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int res = helper(coins, n, sum,dp);
        return (res==INT_MAX || res == INT_MAX-1) ? -1 : res;
    }
};



    

    
    