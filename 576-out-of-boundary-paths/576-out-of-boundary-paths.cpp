class Solution {
public:
    const int mod=1e9+7;
    int dp[51][51][51];
    int dfs(int i,int j,int m,int n,int maxMove){
     if(i<0 or i>=m or j<0 or j>=n) return 1;
     if(maxMove==0) return 0;
     if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove]%mod;
      int ans=0;
      ans=(ans%mod+dfs(i+1,j,m,n,maxMove-1)%mod);
      ans=(ans%mod+dfs(i-1,j,m,n,maxMove-1)%mod);
      ans=(ans%mod+dfs(i,j+1,m,n,maxMove-1)%mod);
      ans=(ans%mod+dfs(i,j-1,m,n,maxMove-1)%mod);
     return dp[i][j][maxMove]=ans%mod;
   }
  
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(startRow,startColumn,m,n,maxMove);
    }
};