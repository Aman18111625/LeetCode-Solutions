class Solution {
public:
    typedef long long ll;
    const ll mod=1e9+7;
    //Recursive+Solution
    //Time-Complexity:=>O(N*K*min(N,k))
    //Space-Complexity:=>O(exponential)
    // int helper(int n,int k){
    //   if(n==0) return 0;
    //   if(k==0) return 1;
    //   long long res=0;
    //   for(int i=0;i<=min(k,n-1);i++){
    //     res=(res+helper(n-1,k-i))%mod;
    //   }
    //   return res;
    // }
    // int kInversePairs(int n, int k) {
    //   return helper(n,k);
    // }
  
    //Recursive+Memoization
    //TC:=>O(N*K*min(N,K))
    //SC:=>O(N*K)+O(N)(stack-space)
    //Got TLE
//     long long helper(long long n,long long k,vector<vector<long long>>&dp){
//         if(n==0) return 0;
//         if(k==0) return 1;
//         // Memoization //
//         if(dp[n][k]!=-1)  return dp[n][k];
//         long long ans=0LL;
//         long long limit=min(k,n-1);   
//         // Transition //
//         for(long long i=0;i<=limit;i++)
//             ans=(ans%mod+helper(n-1,k-i,dp)%mod);
             
//         return dp[n][k] = ans;
//     }
//     int kInversePairs(int n, int k) {
//       vector<vector<long long>>dp(n+2,vector<long long>(k+2,-1));
//       long long ans=helper(n,k,dp);
//       return ans%mod;
//     }
  
    //Bottom-Up
    //TC:=>O(N*K*min(N,K))
    //SC:=>O(N*K)
    //Result:=>Got TLE
//      int kInversePairs(int n, int k) {
//       vector<vector<long long>>dp(n+1,vector<long long>(k+1,0));
//       for(long long i=0;i<=n;i++){
//         for(long long j=0;j<=k;j++){
//           if(j==0) dp[i][j]=1LL;
//           else{
//             long long limit=min(i-1,j);
//             for(long long p=0;p<=limit;p++)
//               dp[i][j]=(dp[i-1][j-p]%mod+dp[i][j]%mod);
                        
//           }
//         }
//       }
//        return dp[n][k];
//     }
  
  //Optimized Approach
  //TC:=>O(N*K)
  //SC:=>O(N*K)
  //Last Approach was giving us TLE so we found out that we need to do some optimized here what we have done instead of storing whole dp we have just prefix array
     int kInversePairs(int n, int k) {
        
        ll dp[n+1][k+1];
        
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=k;j++){
                dp[i][j]=0LL;
            }
        }
        
        
        dp[0][0]=1LL;
        
        for(ll i=1;i<=n;i++){
            
            vector<ll>prefix(k+1,0LL);
            
            prefix[0]=dp[i-1][0];
            
            for(ll j=1;j<=k;j++){
                prefix[j]=(prefix[j-1]+dp[i-1][j])%mod;   
            }
            for(ll j=0;j<=k;j++){
                ll value=prefix[j];
                ll l=min(i-1,j);
                ll left_boundary=j-l;
                if(left_boundary-1>=0){
                    value=(value-prefix[left_boundary-1]+mod)%mod;   
                }
                dp[i][j]=value;   
            }   
        }
        return dp[n][k];
    }
};