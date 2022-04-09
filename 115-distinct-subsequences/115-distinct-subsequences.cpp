class Solution {
  /*Recursive + Memoizaton
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
    }*/
  public:
  /*
    int numDistinct(string s, string t){
        int m=s.length();
        int n=t.length();
        vector<vector<unsigned long  int>>dp(m+1,vector<unsigned long int>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[m][n];
    }*/
   int numDistinct(string s, string t){
     int n=s.size(),m=t.size();
     vector<double>prev(m+1,0),curr(m+1,0);
     prev[0]=curr[0]=1;
     for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
         if(s[i-1]==t[j-1]){
           curr[j]=prev[j-1]+prev[j];
         }else{
           curr[j]=prev[j];
         }
       }
       prev=curr;
     }
     return prev[m];
   }
};