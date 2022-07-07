class Solution {
public:
    int dp[1001];
    int helper(int i,vector<int>&cost){
       if(i>=cost.size()) return 0;
       if(dp[i]!=-1) return dp[i];
       int op1=helper(i+1,cost);
       int op2=helper(i+2,cost);
       return dp[i]=cost[i]+min(op1,op2);
    }
      int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return  min(helper(0,cost),helper(1,cost));
    }
};