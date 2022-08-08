class Solution {
public:
     //Recursive + Memoization ->giving TLE
     //TC:=>O(N*N)
     //SC:=>O(N*N)+O(N)(stack-space)
//     int solve(vector<int>&arr,int ind,int prev,int &n,vector<vector<int>>&dp){
//       if(ind==n) return 0;
//       //not take
//       if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
//       int len=0+solve(arr,ind+1,prev,n,dp);//not take
//       //take
//       if(prev==-1 or arr[ind]>arr[prev]){
//         len=max(len,1+solve(arr,ind+1,ind,n,dp)); 
//       }
//       return dp[ind][prev+1]=len;
//     }
    
//     int lengthOfLIS(vector<int>& v) {
//         int n=v.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         return solve(v,0,-1,n,dp);
//     }
      //Tablulation:=> TC:=>O(N*N) SC:=>O(N*N)
       // int lengthOfLIS(vector<int>& v) {
       //   int n=v.size();
       //   vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       //   for(int ind=n-1;ind>=0;ind--){
       //     for(int prev=ind-1;prev>=-1;prev--){
       //       int len=dp[ind+1][prev+1];
       //       if(prev==-1 or v[ind]>v[prev]){
       //         len=max(len,1+dp[ind+1][ind+1]);
       //       }
       //       dp[ind][prev+1]=len;
       //     }
       //   }
       //  return dp[0][0];
       // }
  //TC:=>O(N^2) SC:=>O(N)
   // int lengthOfLIS(vector<int>& v) {
   //      int n=v.size();
   //      vector<int>next(n+1,0),curr(n+1,0);
   //      for(int ind=n-1;ind>=0;ind--){
   //        for(int prev=ind-1;prev>=-1;prev--){
   //          int len=next[prev+1];
   //          if(prev==-1 or v[ind]>v[prev]){
   //            len=max(len,1+next[ind+1]);
   //          }
   //          curr[prev+1]=len;
   //        }
   //        next=curr;
   //      }
   //      return next[0];
   //  }
  //Best Solution
  //TC:=>O(N*N)
  //SC:=>O(N)
   int lengthOfLIS(vector<int>&v){
     int n=v.size();
     vector<int>dp(n,1);
     int maxi=1;
     for(int ind=0;ind<n;ind++){
       for(int prev=0;prev<ind;prev++){
         if(v[prev]<v[ind]){
           dp[ind]=max(dp[ind],1+dp[prev]);
         }
       }
       maxi=max(maxi,dp[ind]);
     }
    return maxi;
   }
};