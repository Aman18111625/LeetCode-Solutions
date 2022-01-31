class Solution {
  /*
  //Recursive+Memoization
  //TC:=>O(N*M) SC:=>O(N*M)
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
  /*Bottom -Up Approach 
  //TC:=>O(N*M) SC:=>O(N*M)
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
    }*/
  
  //Space-Optimization
  //TC:=>O(N*M)
  //SC:=>O(N)
  /*
If we closely look the relation,
dp[i][j] = dp[i-1][j] + dp[i][j-1])
We see that we only need the previous row and column,in order to calculate dp[i][j]. Therefore we can space optimize it.
Initially, we can take a dummy row ( say prev) and initialize it as 0.
Now the current row only needs the previous row value and the current row’s value in order to calculate dp[i][j].
*/
   int uniquePathsWithObstacles(vector<vector<int>>&grid)
   {
        int row = grid.size(), col = grid[0].size();
        vector<int> res(col, 0);
        res[0] = 1;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) res[j] = 0;//if grid[i][j] is obstacle then simply store zero else check for previous row
                else if (j > 0) res[j] += res[j - 1];
            }
        }
        return res[col - 1];
   }
};