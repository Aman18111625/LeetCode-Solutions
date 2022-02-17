class Solution {
  /*
  //Recursive+Memoization
  //Time-Complexity:=>O(N*amount)
  //Space-Complexity:=>O(N*amount)+O(N)
int helper(vector<int>&coins,int index,int n,int amount,vector<vector<int>>&dp)
    {
        if(amount==0) return 1;//we got desired amount
        if(amount<0 or index>=n) return 0;//out of bound
        if(dp[index][amount]!=-1) return dp[index][amount];
  //for every number we have two choices ->we can choose it and move to the same index or ignore & move to next index
        int take=0,notTake=0;
        if(coins[index]<=amount)
        {
          take=helper(coins,index,n,amount-coins[index],dp);
        }
         notTake=helper(coins,index+1,n,amount,dp);
        return dp[index][amount]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
      int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins,0,n,amount,dp);
    }*/
    public:
  /*
  //Tabulation
  //Time-Complexity:=>O(N*amount)
  //Space-Complexity:=>O(N*amount)
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
         for(int amt=0;amt<=amount;amt++)
         {
           dp[0][amt]=(amt%coins[0]==0);
         }
         for(int ind=1;ind<n;ind++){
           for(int t=0;t<=amount;t++){
             int notTake=dp[ind-1][t];
             int take=0;
             if(coins[ind]<=t) take=dp[ind][t-coins[ind]];
               dp[ind][t]=notTake+take;
           }
         }
      return dp[n-1][amount];
    }*/
   int change(int amount, vector<int>& coins) {
         int n=coins.size();
         vector<int>prev(amount+1,0),curr(amount+1,0);
         for(int amt=0;amt<=amount;amt++)
         {
           prev[amt]=(amt%coins[0]==0);
         }
         for(int ind=1;ind<n;ind++){
           for(int t=0;t<=amount;t++){
             int notTake=prev[t];
             int take=0;
             if(coins[ind]<=t) take=curr[t-coins[ind]];
               curr[t]=notTake+take;
           }
           prev=curr;
         }
      return prev[amount];
    }
};