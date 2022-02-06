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
  /*
  //Recursive+Memoization or Top-down Approach
  //Time-Complexity:=>O(N*(N*N)
  //Space-Complexity:=>O(N)(stack-space) + O(N*N)(dp array)
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
  */
  public:
  /*
  //Tabulation 
  //Time-Complexity:=>O(N*N)
  //Space-Complexity:=>O(N*N)
    int minimumTotal(vector<vector<int>>& triangle) {
      int n=triangle.size();
       vector<vector<int>>dp(n,vector<int>(n)); 
       for(int j=0;j<n;j++)//base case
          dp[n-1][j]=triangle[n-1][j];
      
      for(int i=n-2;i>=0;i--)
      {
         for(int j=i;j>=0;j--)
         {
            int down=dp[i+1][j];
            int diag=dp[i+1][j+1];
           dp[i][j]=triangle[i][j]+min(down,diag);
         }
      }
      return dp[0][0];
    }*/
  
   int minimumTotal(vector<vector<int>>& triangle) {
      int n=triangle.size();
       vector<int>prev(n);
       for(int j=0;j<n;j++)//base case
          prev[j]=triangle[n-1][j];
      
      for(int i=n-2;i>=0;i--)
      {
         vector<int>curr(n);
         for(int j=i;j>=0;j--)
         {
            int down=prev[j];
            int diag=prev[j+1];
            curr[j]=triangle[i][j]+min(down,diag);
         }
        prev=curr;
      }
      return prev[0];
    }
};