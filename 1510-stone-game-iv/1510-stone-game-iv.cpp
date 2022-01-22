class Solution {
  int dp[100001];
  bool helper(int n)
  {
    if(n<=0) return false;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i*i<=n;i++)
    {
      if(!helper(n-i*i)) return dp[n]=true;
    }
    return dp[n]=false;
  }
public:
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};
 