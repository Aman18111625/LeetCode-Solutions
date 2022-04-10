class Solution {
  int dp[501][501];
  int helper(string& a,string& b,int i,int j)
    {
        if(i==a.size()) return b.size()-j;
        if(j==b.size()) return a.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]=helper(a,b,i+1,j+1);
        int l=1+helper(a,b,i,j+1);
        int m=1+helper(a,b,i+1,j);
        int r=1+helper(a,b,i+1,j+1);
        return dp[i][j]=min(l,min(m,r));
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return helper(word1,word2,0,0);
    }
};