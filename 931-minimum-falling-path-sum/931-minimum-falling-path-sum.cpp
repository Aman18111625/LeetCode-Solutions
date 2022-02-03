class Solution {
int dp[101][101];
int helper(int i,int j,int n,int m,vector<vector<int>>&a)
{
    if(j<0 || j>=m)
        return 1e6;
    if(i==0)
        return a[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int up = a[i][j] + helper(i-1,j,n,m,a);
    int ld = a[i][j] + helper(i-1,j-1,n,m,a);
    int rd = a[i][j] + helper(i-1,j+1,n,m,a);
    return dp[i][j]=min(up,min(ld,rd));
}
public:
int minFallingPathSum(vector<vector<int>>& matrix) {
    memset(dp,-1,sizeof(dp));
    int ans=INT_MAX;
    int n=matrix.size(),m=matrix[0].size();   
    for(int j=0;j<m;j++)
        ans=min(ans,helper(n-1,j,n,m,matrix));
     
    return ans;
  }
};