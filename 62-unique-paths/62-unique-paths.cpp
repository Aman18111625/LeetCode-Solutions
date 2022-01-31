class Solution {
  /*Recursive and memoization: TC:=>O(M*N) SC:=>O(M*N)
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
    }*/
  public:
  /*
  //Bottom-up DP
  //TC:=>O(M*N) SC:=>(M*N)
  int uniquePaths(int m, int n) {
        int dp[m][n];
        //from top to down
        for(int i = 0; i < m; ++i)
            dp[i][0] = 1;
        //from left to right
        for(int j = 1; j < n; ++j)
            dp[0][j] = 1;
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }*/
  
  //Using combinations 
  //TC:=>O(min(m-1,n-1))
  //SC:=>O(1)
    int uniquePaths(int m, int n) {
        int N = n + m -2;  //N=3
        int r = m-1;       //right = 2
        double res = 1;   //result = 1
        for(int i=1;i<=r;i++) {
            res = res * (N-r+i)/i;
        }
        return (int)res;
    }
};