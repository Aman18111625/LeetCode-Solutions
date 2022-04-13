class Solution {
  /*
  //Recursive + Memoization
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
    }*/
  public:
  /*tabulation
    int minDistance(string a, string b){
      int n=a.size(),m=b.size();
      vector<vector<int>>dp(n,vector<int>(m,0));
      for(int i=0;i<=n;i++) dp[i][0]=i;
      for(int j=0;j<=m;j++) dp[0][j]=j;
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          if(a[i-1]==b[j-1]){
            dp[i][j]=dp[i-1][j-1];
          }else{
            dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
          }
        }
      }
      return dp[n];
    }*/
  int minDistance(string a, string b){
      int n=a.size(),m=b.size();
      vector<int>prev(m+1,0),curr(m+1,0);
      for(int i=0;i<=m;i++){
        prev[i]=i;
      }
    
      for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
          if(a[i-1]==b[j-1]){
            curr[j]=prev[j-1];
          }else{
            curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
          }
        }
        prev=curr;
      }
      return prev[m];
    }
};