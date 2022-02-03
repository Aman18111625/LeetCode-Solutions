class Solution {
  /*
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
  }*/
  public:
  
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size(), m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++)
        dp[0][j]=matrix[0][j];
        
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int ld=1e9,rd=1e9;
            int up=matrix[i][j] + dp[i-1][j];
            if(j-1>=0)
                ld=matrix[i][j] + dp[i-1][j-1];
            if(j+1<m)
                rd=matrix[i][j] + dp[i-1][j+1];
            dp[i][j] = min(up,min(ld,rd));
        }
    }
    int mini=dp[n-1][0];
    for(int j=1;j<m;j++)        
        mini=min(mini,dp[n-1][j]);
        
    return mini;
  }
};