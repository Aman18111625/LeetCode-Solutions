class Solution {
public:
  /* Recursive :=>TC =O(2^N) SC =O(N)
    int climbStairs(int n) {
        if(n<2) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }*/
    int climbStairs(int n){
       int dp[n+1];
      dp[0]=0,dp[1]=1;
      if(n>=2) dp[2]=2;
      for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
      return dp[n];
    }
};