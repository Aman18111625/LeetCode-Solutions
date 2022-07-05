class Solution {
public:
   //Recursive+Memoization
  //TC:=>O(N*M)
  //SC:=>O(N*M)+O(max(N,M))(stack-space)
//    int n,m;//n->size of nums1 , m->size of nums2
//    int helper(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){
//      if(i>=n or j>=m) return 0;
//      if(dp[i][j]!=-1) return dp[i][j];
//      //here we have 4 options-> 1.either we can take both the i,j
//      //2. we can't both 3. we can take i not j 4.we can take j not i.
//      int op1=nums1[i]*nums2[j]+helper(nums1,nums2,i+1,j+1,dp);
//      int op2=helper(nums1,nums2,i+1,j+1,dp);
//      int op3=helper(nums1,nums2,i+1,j,dp);
//      int op4=helper(nums1,nums2,i,j+1,dp);
//      return dp[i][j]=max({op1,op2,op3,op4});
//    }
   
    
//     int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//          n=nums1.size(),m=nums2.size();
//          vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//          int res= helper(nums1,nums2,0,0,dp);//here i can't simple return helper because result can be negative 
//         if(res==0){
//           int maxi1=INT_MIN,mini1=INT_MAX;
//           for(auto &num : nums1){
//             if(num==0) return 0;
//             maxi1=max(maxi1,num);
//             mini1=min(mini1,num);
//           }
//           int maxi2=INT_MIN,mini2=INT_MAX;
//           for(auto &num : nums2){
//             if(num==0) return 0;
//             maxi2=max(maxi2,num);
//             mini2=min(mini2,num);
//           }
//           return max(maxi1*mini2,maxi2*mini1);
//         }
//         return res;
//     }
  
  //Bottom-Up Approach
  //TC:=>O(N*M)
  //SC:=>O(N*M)
//Intution:=>Very similar to LCS, dp[i][j] means what is the maximum dot product if we use nums1[0..i-1] and nums2[0...j-1]
//Boundary case is we end up creating an empty dot product. That can happen only when one array is completely negative and one is completely positive. Therefore for such cases we find max and min of both the array and took max(max1*min2,max2*min1)
  
//   int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size(), m = nums2.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=m; j++){
//               dp[i][j] = max(dp[i-1][j-1] + nums1[i-1] * nums2[j-1], max(dp[i-1][j], dp[i][j-1]));
//             }
//         }
//         //edge case
//         if(dp[n][m]==0){
//           int maxi1=INT_MIN,mini1=INT_MAX;
//           int maxi2=INT_MIN,mini2=INT_MAX;
//           for(auto &num : nums1){
//             maxi1=max(maxi1,num);
//             mini1=min(mini1,num);
//           }
//           for(auto &num : nums2){
//             maxi2=max(maxi2,num);
//             mini2=min(mini2,num);
//           }
//           return max(mini1*maxi2,maxi1*mini2);
//         }
//         return dp[n][m];
//     }
  
  
  //space-optimization
  //TC:=>O(N*M)
  //SC:=>O(M)
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int>prev(m+1, 0),curr(m+1,0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
              curr[j] = max(prev[j-1] + nums1[i-1] * nums2[j-1], max(prev[j], curr[j-1]));
            }
            prev=curr;
        }
        //edge case
        if(prev[m]==0){
          int maxi1=INT_MIN,mini1=INT_MAX;
          int maxi2=INT_MIN,mini2=INT_MAX;
          for(auto &num : nums1){
            maxi1=max(maxi1,num);
            mini1=min(mini1,num);
          }
          for(auto &num : nums2){
            maxi2=max(maxi2,num);
            mini2=min(mini2,num);
          }
          return max(mini1*maxi2,maxi1*mini2);
        }
        return prev[m];
    }
};






