class Solution {
int helper(vector<int>&coins,int index,int n,int amount,vector<vector<int>>&dp)
    {
        if(amount==0) return 1;
        if(amount<0 or index>=n) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int left=helper(coins,index,n,amount-coins[index],dp);
        int right=helper(coins,index+1,n,amount,dp);
        return dp[index][amount]=left+right;
    }
public:
    int change(int amount, vector<int>& coins) {
      int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins,0,n,amount,dp);
    }
};