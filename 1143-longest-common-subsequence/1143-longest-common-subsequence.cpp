class Solution {
  /*Recursive+ Memoization
  //Time-Complexity:=>O(N*M)
  //Space-Complexity:=>O(N*M)+O(N+M)(stack-space)
    int helper(string& a,string& b,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0 or m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m]; 
        if(a[n-1]==b[m-1]) return dp[n][m]=1+helper(a,b,n-1,m-1,dp);
        return dp[n][m]=max(helper(a,b,n-1,m,dp),helper(a,b,n,m-1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size(),m=text2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return helper(text1,text2,n,m,dp);
    }
  public:
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size(),m=text2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return helper(text1,text2,n,m,dp);
    }*/
    public:
  /*
  //Bottom-Up
  //TC:=>O(N*M)
  //SC:=>O(N*M)
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size(),m=text2.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1));
       for(int i=0;i<=n;i++){
         for(int j=0;j<=m;j++){
            if(i==0 or j==0) continue;
            else if(text1[i-1]==text2[j-1]){
              dp[i][j]=1+dp[i-1][j-1];
            }else{
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
         }
       }
      return dp[n][m];
    }*/
  //Space-Optimization
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size(),m=text2.size();
         vector<int>prev(m+1,0),curr(m+1,0);
       for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
           if(text1[i-1]==text2[j-1]){
              curr[j]=1+prev[j-1];
            }else{
              curr[j]=max(prev[j],curr[j-1]);
            }
         }
         prev=curr;
       }
      return prev[m];
    }
};