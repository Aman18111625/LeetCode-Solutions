class Solution {
//Recursive + Memoization
//Time-Complexity: =>O(N*SQRT(N))
//Space-Complexity: =>O(N)+O(N)(stack-space)
//    int solve(int n,vector<int>&dp) {
//         if (n == 0) return 0;
//         if(dp[n]!=-1) return dp[n];
//         int ans=INT_MAX;
//         for(int i=1; i*i<=n; i++) {
//             ans = min(ans, solve(n-(i*i),dp)+1);
//         }
//         return dp[n]=ans;
//     }
// public:
//     int numSquares(int n) {
//         vector <int> dp(n+1, -1);
//         int ans = solve(n,dp);
//         return ans;
//     }
  public:
  //Bottom-Up Approach
  //Time-Complexity:=>O(N*SQRT(N))
  //Space-Complexity:=>O(N)
  int numSquares(int n) {
        if(n==1) return 1;
        int dp[n+1];
         dp[0]=0;
         dp[1]=1;
        for(int i=2;i<=n;i++){
            int mini=INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                int r=i-j*j;
                mini=min(mini,dp[r]);
            }
            dp[i]=mini+1;
        }
        return dp[n];
    }
};