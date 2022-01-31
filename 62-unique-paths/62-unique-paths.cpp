class Solution {
  int dp[101][101];
  int helper(int i,int j,int &m,int &n)
  {
    if(i>=m || j>=n) return 0;
    if(i==m-1 && j==n-1) return dp[i][j]=1;
    if(dp[i][j]!=-1) return dp[i][j];
    int op1=helper(i+1,j,m,n);
    int op2=helper(i,j+1,m,n);
    return dp[i][j]=op1+op2;
  }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,m,n);
    }
};