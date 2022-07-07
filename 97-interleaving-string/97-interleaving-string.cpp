class Solution {
public:
    int dp[101][101];
    bool helper(string &s1,string &s2,string &s3,int i,int j,int k){
      if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
      if(dp[i][j]!=-1) return dp[i][j];
      bool res=false;
      if(i!=s1.size() && s1[i]==s3[k])
         res|=helper(s1,s2,s3,i+1,j,k+1);
      if(j!=s2.size() && s2[j]==s3[k])
          res|=helper(s1,s2,s3,i,j+1,k+1);
        
      return dp[i][j]=res;    
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size();
        if(s3.size()==0) return true;
        if(n+m!=s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        return helper(s1,s2,s3,0,0,0);
    }
};

