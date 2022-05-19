class Solution {
public:
    int dp[201][201];
    int helper(vector<vector<int>>&mat,int i, int j)
    {
        if(dp[i][j]) return dp[i][j];
        int res=1;
        if(i+1<mat.size() && mat[i+1][j]>mat[i][j])  res=max(res,1+helper(mat,i+1,j));
        if(i>=1 && mat[i-1][j]>mat[i][j]) res=max(res,1+helper(mat,i-1,j));
        if(j+1<mat[0].size() && mat[i][j+1]>mat[i][j]) res=max(res,1+helper(mat,i,j+1));
        if(j>=1 && mat[i][j-1]>mat[i][j]) res=max(res,1+helper(mat,i,j-1));
        return dp[i][j]=res;
    }
  
    int longestIncreasingPath(vector<vector<int>>& mat) {
        if(mat.empty()) return 0;
        int row=mat.size();
        int col=mat[0].size();
        int res=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                res=max(res,helper(mat,i,j));
            }
        }
        return res;  
    }
};