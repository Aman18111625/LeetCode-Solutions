class Solution {
    int dp[1001][1001];
    int helper(string& a,string& b,int n,int m)
    {
        if(n==0 or m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m]; 
        if(a[n-1]==b[m-1]) return dp[n][m]=1+helper(a,b,n-1,m-1);
        return dp[n][m]=max(helper(a,b,n-1,m),helper(a,b,n,m-1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size(),m=text2.size();
      memset(dp,-1,sizeof(dp));
      return helper(text1,text2,n,m);
    }
};