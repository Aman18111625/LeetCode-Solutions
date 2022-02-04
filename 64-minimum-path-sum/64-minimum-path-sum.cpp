class Solution {
  /*Recursive + Memoization 
  Time-Complexity:=>O(N*M)
  Space-Complexity:=>O(N*M)+O(N)(space-stack)
  int dp[201][201];
  int helper(vector<vector<int>>&grid,int i,int j,int& n,int &m){
            //out of matrix
           if(i>=n || j>=m) return INT_MAX;
            //base case -> we reach at extreme bottom right corner
           if(i==n-1 && j==m-1) return dp[i][j]=grid[i][j];
           if(dp[i][j]!=-1) return dp[i][j];
           //now we have two option we can either go to down or go to right
           int op1=helper(grid,i+1,j,n,m);
           int op2=helper(grid,i,j+1,n,m);
           return dp[i][j]=grid[i][j]+min(op1,op2);
  }
public:
    int minPathSum(vector<vector<int>>& grid) {
         int n=grid.size(),m=grid[0].size();
         memset(dp,-1,sizeof(dp));
         return helper(grid,0,0,n,m);
    }*/
  public:
  //Bottom-up Solution 
  //Time-Complexity:=>O(N*M)
  //Space-Complexity:=>O(N*M)
  int minPathSum(vector<vector<int>> &grid) {
    // Write your code here.
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        for(int i=n-1;i>=0;i--)
        {
         for(int j=m-1;j>=0;j--)
         {
              if(i==n-1 and j==m-1) //last index 
              {
               dp[i][j]=grid[i][j];   
              }
             else if(i==n-1) //last row
             {
                 dp[i][j]=dp[i][j+1]+grid[i][j];
             }
             else if(j==m-1) //last column
             {
                 dp[i][j]=dp[i+1][j]+grid[i][j];
             }
             else
             {
                 dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
             }
         }
        }
        return dp[0][0];
}
};

