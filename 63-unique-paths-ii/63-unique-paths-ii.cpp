class Solution {
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
    }
};