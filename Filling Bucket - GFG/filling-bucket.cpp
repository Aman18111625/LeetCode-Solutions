//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    const int mod=1e8;
 
  public:
    int fillingBucket(int N) {
        // code here
        vector<int>dp(N);
        if (N<=2) return N;
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<N;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        return dp[N-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends