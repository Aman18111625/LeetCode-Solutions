class Solution {
public:
  /* Recursive :=>TC =O(2^N) SC =O(N)
    int climbStairs(int n) {
        if(n<2) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }*/
  /*
  //Recursive + Memoization
  //TC:=>O(N) SC:=>O(N)
    int dp[46];
   int helper(int n)
   {
     if(n<2) return dp[n]=1;
     if(dp[n]!=-1) return dp[n];
     int op1=helper(n-1);
     int op2=helper(n-2);
     dp[n]=op1+op2;
     return dp[n];
   }
   int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
     return helper(n);
    }
    */
  /*
  //Bottom-up approach :=>TC =(N) SC=O(N)
    int climbStairs(int n){
       int dp[n+1];
      dp[0]=0,dp[1]=1;
      if(n>=2) dp[2]=2;
      for(int i=3;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
      return dp[n];
    }*/
   int climbStairs(int n) {
    if(n<2) return 1;
     int prev=1,next=2,curr=2;
     for(int i=3;i<=n;i++)
     {
       curr=prev+next;
       prev=next;
       next=curr;
     }
     return curr;
  }
};