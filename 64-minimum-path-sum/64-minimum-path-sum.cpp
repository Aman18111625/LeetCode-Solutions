class Solution {
  int dp[201][201];
  int helper(vector<vector<int>>&grid,int i,int j,int& n,int &m){
            //out of matrix
           if(i>=n || j>=m) return INT_MAX;
            //base case -> we reacj extreme bottom right corner
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
    }
};

