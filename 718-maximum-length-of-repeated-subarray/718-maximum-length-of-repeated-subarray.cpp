class Solution {
public:
  //Brute-Force Approach:->Using Recursion
  //TC:=>O(3^(M+N))
  //SC:=>O(N+M)
//    int ans=0;
   
//    int solve(vector<int>& A, vector<int>& B, int i, int j) {
// 		if(i >= size(A) || j >= size(B)) return 0;
// 		solve(A, B, i+1, j), solve(A, B, i, j+1);// recurse to solve for each possible (i, j)
// 		int common=(A[i] == B[j])?1+solve(A, B, i+1, j+1):0;//longest common subarray starting at A[i] & B[j]
// 		ans = max(ans, common); // update ans to hold max length found till now
// 		return common;
// 	}
  
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//       if(nums1==nums2) return nums1.size();
//       solve(nums1,nums2,0,0);
//       return ans;
//     }
  
//Optimized Approach:=>Recursion+DP
//TC:=>O(N+M)
//SC:=>O(N+M)

//    int ans=0;
   
//    int solve(vector<int>& A, vector<int>& B, int i, int j,vector<vector<int>>&dp){
// 		if(i >= size(A) || j >= size(B)) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
// 		solve(A, B, i+1, j,dp), solve(A, B, i, j+1,dp);// recurse to solve for each possible (i, j)
// 		int common=(A[i] == B[j])?1+solve(A, B, i+1, j+1,dp):0;//longest common subarray starting at A[i] & B[j]
// 		ans = max(ans, common); // update ans to hold max length found till now
// 		return dp[i][j]=common;
// 	}
  
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//       if(nums1==nums2) return nums1.size();
//       int n=nums1.size(),m=nums2.size();
//       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//       solve(nums1,nums2,0,0,dp);
//       return ans;
//     }
  
  //Bottom-Up Approach:
  //TC:=>O(M*N)
  //SC:=>O(M*N)  
   // int findLength(vector<int>& nums1, vector<int>& nums2) {
   //      if(nums1==nums2) return nums1.size();
   //      int n=nums1.size(),m=nums2.size();
   //      int dp[n+1][m+1];
   //      memset(dp,0,sizeof(dp));
   //      int ans=0;
   //      for(int i=1;i<=n;i++){
   //       for(int j=1;j<=m;j++){
   //        if(nums1[i-1]==nums2[j-1]){
   //          dp[i][j]=dp[i-1][j-1]+1;
   //        }
   //         ans=max(ans,dp[i][j]);
   //       }  
   //      }
   //      return ans;
   //  }
  
  //Space-Optimization
  //TC:=>O(N*M)
  //SC:=>O(M)
  
   int findLength(vector<int>& nums1, vector<int>& nums2) {
      if(nums1==nums2) return nums1.size();
      if(nums1.size()<nums2.size()) swap(nums1,nums2); 
      int n = nums1.size(), m = nums2.size();
      vector<int>dp(m+1,0);
      int  ans=0;
        
      for(int i=1;i<=n;i++){
        for(int j=m;j>0;j--){
         if(nums1[i-1]==nums2[j-1]){
            dp[j]=1+dp[j-1];
            if(dp[j]>ans){
             ans = dp[j];
             if(ans==m)
              return ans;
           }
         }   
         else
            dp[j]=0;
        }
      }
      return ans;
    }
};
