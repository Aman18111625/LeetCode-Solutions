// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	const int mod=1e9+7;
	int helper(int N,vector<int>&dp)
    {
       if(N==0)
	        return 1;
	    if(N==1)
	        return 2;
	    if(dp[N]!=-1)
	        return dp[N];
	    else
	        return dp[N] = (helper(N-1,dp)%mod+ helper(N-2,dp)%mod)%mod;
    }
	int TotalWays(int N)
	{
	    vector<int>dp(N+1,-1);
	    long long int ans = helper(N,dp)%mod;
	    return (ans*ans)%mod;
	}
	
// 	int TotalWays(int n)
// 	{
// 	    // Code here
// 	    int mod=1e9+7;
// 	    if(n==0) return 1;
// 	    if(n==1) return 4;
// 	    int a=1,b=2;
// 	    long long int ans=0;
// 	    for(int i=2;i<=n;i++){
// 	        ans=(a+b)%mod;
// 	        a=b;
// 	        b=ans;
// 	    }
// 	    return (ans*ans)%mod;
// 	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends