class Solution {
public:
    int countOrders(int n) {
        if(n==1) return 1;
        int mod=1e9+7;
        long long res=1;
        for(int i = 1; i <=n; ++i)
        {
		   	// calulating n!
            res *= i;
			// to avoid overflow
           res %= mod;
			
			// (2*i-1) are the vacant places which we can choose
			// later we have n! permutation of pickup task
			// therefore we have to multiply with n! that we calculated as res.
            res *= (2*i-1);
			// to avoid overflow
           res %= mod;
        }
      return res;
    /*TC:=>O(N) SC:=>O(N)
      vector<long long>dp(n);
      dp[0]=1;
      for(int i=1;i<n;i++){
        long long gaps = 2*i+1;
        long long ways = (gaps*gaps)-(gaps*(gaps-1))/2;
        dp[i]=(dp[i-1]*ways)%mod;
      }
      return dp[n-1];*/
        
    }
};