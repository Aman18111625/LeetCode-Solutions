class Solution {
public:
//Recursive+Memoization
//TC:=>O(N*M)
//SC:=>O(N*M)+O(max(N,M))(stack-space)
//     int dp[101][101];
//     bool helper(string &s1,string &s2,string &s3,int i,int j,int k){
//       if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
//       if(dp[i][j]!=-1) return dp[i][j];
//       bool res=false;
//       if(i!=s1.size() && s1[i]==s3[k])
//          res|=helper(s1,s2,s3,i+1,j,k+1);
//       if(j!=s2.size() && s2[j]==s3[k])
//           res|=helper(s1,s2,s3,i,j+1,k+1);
        
//       return dp[i][j]=res;    
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         int n=s1.size(),m=s2.size();
//         if(s3.size()==0) return true;
//         if(n+m!=s3.size()) return false;
//         memset(dp,-1,sizeof(dp));
//         return helper(s1,s2,s3,0,0,0);
//     }
  
  //Bottom Approach
  //TC:=>O(N*M)
  //SC:=>O(N*M)
//   bool isInterleave(string s1, string s2, string s3) {
//         int n=s1.length();
//         int m=s2.length();
//         if(s3.size()==0) return true;
//         if(n+m!=s3.length())  return 0;
//         vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=m;j++){
//                 if(i==0&&j==0)
//                     dp[i][j]=true;
//                 else if(i==0){
//                     if(s2[j-1]==s3[j-1])
//                         dp[i][j]=dp[i][j-1];
//                 }
//                 else if(j==0){
//                     if(s1[i-1]==s3[i-1])
//                         dp[i][j]=dp[i-1][j];
//                 }
//                 else if(s1[i-1]==s3[i+j-1]&&s2[j-1]!=s3[i+j-1])
//                     dp[i][j]=dp[i-1][j];
                
//                 else if(s1[i-1]!=s3[i+j-1]&&s2[j-1]==s3[i+j-1])
//                     dp[i][j]=dp[i][j-1];
                
//                 else if(s1[i-1]==s3[i+j-1]&&s2[j-1]==s3[i+j-1])
//                     dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
//             }
//         }
//         return dp[n][m];
//     }
  
  //space-optimization
  //TC:=>O(N*M)
  //SC:=>O(M)
   bool isInterleave(string s1, string s2, string s3) {
        vector<int>cur(s2.size()+1,0),prev(s2.size()+1,0);
        if(s3.size()!=s1.size()+s2.size()){
            return false;
        }
        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                int k=i+j;
                if(i==s1.size()&&j==s2.size()){
                    cur[j]=1;
                }
                else if(s3[k]==s2[j]&&s3[k]==s1[i]){
                    cur[j]= prev[j]||cur[j+1];
                }
                else if(s1[i]==s3[k]){
                    cur[j]= prev[j];
                }
                else if(s3[k]==s2[j]){
                    cur[j]= cur[j+1];
                }
                else{
                    cur[j]= false;
                }  
            }
            prev=cur;
        }
        return cur[0];
    }
};
 