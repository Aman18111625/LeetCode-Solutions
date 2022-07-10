class Solution {
public:
    //Recursive+Memoization
    // int dp[1001];
    // int helper(int i,vector<int>&cost){
    //    if(i>=cost.size()) return 0;
    //    if(dp[i]!=-1) return dp[i];
    //    int op1=helper(i+1,cost);
    //    int op2=helper(i+2,cost);
    //    return dp[i]=cost[i]+min(op1,op2);
    // }
    //   int minCostClimbingStairs(vector<int>& cost) {
    //     memset(dp,-1,sizeof(dp));
    //     return  min(helper(0,cost),helper(1,cost));
    // }
  
  //Bottom-Up Approach;
//    int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int>dp(n+2);
//         dp[n]=0;
//         dp[n+1]=0;
//         for(int i=n-1;i>=0;i--)
//             dp[i]=cost[i]+min(dp[i+1],dp[i+2]);
        
//         return min(dp[0],dp[1]);
//     }
  
   //space-optimization
   int minCostClimbingStairs(vector<int>& cost) {
        int dp1=0,dp2=0;
        int n=cost.size();
        for(int i=n-1;i>=0;i--)
        {
            int dpi=cost[i]+min(dp1,dp2);
            dp2=dp1;
            dp1=dpi;
        }
        return min(dp1,dp2);
    }
};