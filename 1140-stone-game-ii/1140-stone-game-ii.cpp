class Solution {
    int dp[101][101];
    int helper(int i,int M,vector<int>&p,int& size)
    {
      if(i>=size) return 0;
      if(dp[i][M]!=-1) return dp[i][M];
      int total=0;
      int ans=INT_MIN;
      for(int j=0;j<2*M;j++)
      {
        if(i+j<size) total+=p[i+j];
        ans=max(ans,total-helper(i+j+1,max(M,j+1),p,size));
      }
      return dp[i][M]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        if(n==1) return piles[0];
         memset(dp,-1,sizeof(dp));
        int diff=helper(0,1,piles,n);
         int sum=0;
        for(int i=0;i<n;i++) sum+=piles[i];
        return (sum+diff)>>1;
    }
};