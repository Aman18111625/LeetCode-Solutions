class Solution {
  /*//Recursive Solution :
     Time-Complexity:=>exponential
     Space-Complexity:=>O(N)(stack-space)
    int helper(vector<vector<int>>&grid,int i,int j)
    {
      int n=grid.size();
      if(i==n-1) return grid[i][j];
      if(j>=n) return 0;
      //now we have two option either we can go down or diagonally
      //(i,j)->(i+1,j) or (i+1,j+1)
      int down=helper(grid,i+1,j);
      int diag=helper(grid,i+1,j+1);
      return grid[i][j]+min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle,0,0);
    }*/
    int dp[201][201];
   int helper(vector<vector<int>>&grid,int i,int j)
    {
      int n=grid.size();
      if(i==n-1) return dp[i][j]=grid[i][j];
      if(j>=n) return 0;
      if(dp[i][j]!=-1) return dp[i][j];
      //now we have two option either we can go down or diagonally
      //(i,j)->(i+1,j) or (i+1,j+1)
      int down=helper(grid,i+1,j);
      int diag=helper(grid,i+1,j+1);
      return dp[i][j]=grid[i][j]+min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return helper(triangle,0,0);
    }
};