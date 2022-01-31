class Solution {
  /*
  int dp[101][101];
  int helper(vector<vector<int>>&grid,int i,int j)
  {
     if(i<0 || j<0 || grid[i][j]) return 0;
     if(i==0 && j==0) return dp[i][j]=1;
     if(dp[i][j]!=-1) return dp[i][j];
     int left=helper(grid,i-1,j);
     int up=helper(grid,i,j-1);
    return dp[i][j]=left+up;
  }
public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
       int n=grid.size(),m=grid[0].size();
       memset(dp,-1,sizeof(dp));
      return helper(grid,n-1,m-1);
    }*/
  public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid){
      int n=grid.size(),m=grid[0].size();
      int dp[n][m];
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(grid[i][j]==1) dp[i][j]=0;
          else if(i==0 && j==0) dp[i][j]=1;
          else {
            int left=0,up=0;
            if(i>0) up=dp[i-1][j];
            if(j>0) left=dp[i][j-1];
            dp[i][j]=left+up;
          }
        }
      }
      return dp[n-1][m-1];
    }
};