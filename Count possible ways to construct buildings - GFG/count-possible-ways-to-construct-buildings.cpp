// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int n)
	{
	    // Code here
	    int mod=1e9+7;
	    if(n==0) return 1;
	    if(n==1) return 4;
	    int a=1,b=2;
	    long long int ans=0;
	    for(int i=2;i<=n;i++){
	        ans=(a+b)%mod;
	        a=b;
	        b=ans;
	    }
	    return (ans*ans)%mod;
	}
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