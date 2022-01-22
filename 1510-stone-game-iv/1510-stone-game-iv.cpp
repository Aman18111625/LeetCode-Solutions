class Solution {
public:
    vector<int> dp;
    Solution() : dp(100001,-1) {}
    bool winnerSquareGame(int n) {
          if(n==0) return false;
          if(dp[n]!=-1) return dp[n];
          bool ans=false;
          for(int i=1;i*i<=n;i++)
          {
            if(!winnerSquareGame(n-i*i)) 
            {
              ans=true; break;
            }
          }
      return dp[n]=ans;
    }
};
 