class Solution {
  int dp[1001][1001];
  int helper(string &s,string& t,int i,int j){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i] == t[j]) 
    {
      return dp[i][j]=helper(s,t,i-1,j-1)+helper(s,t,i-1,j);
    }
    return dp[i][j]=helper(s,t,i-1,j);
  }
public:
    int numDistinct(string s, string t) {
      int m=s.size();
      int n=t.size();
      memset(dp,-1,sizeof(dp));
      return helper(s,t,m-1,n-1);
    }
};