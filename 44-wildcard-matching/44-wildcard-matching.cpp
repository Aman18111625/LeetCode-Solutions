class Solution {
 bool helper(string& s,string&p,int i,int j,vector<vector<int>>&dp){
        if(j==p.length()) return i==s.length();
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j]=='*'){
           for(int k=i;k<=s.length();k++) 
            if(helper(s,p,k,j+1,dp)) return dp[i][j]=true;
                                               
            return dp[i][j]=false;
        }
        if(i<s.length() && (s[i]==p[j] or p[j]=='?')) 
          return dp[i][j]=helper(s,p,i+1,j+1,dp);
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
      vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
      return helper(s,p,0,0,dp);   
    }
};