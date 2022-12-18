//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    long long helper(int n){
        long long ans=n;
        int cnt=3;
        for(long long i=n-1;i>0;i--){
            if(cnt==0) break;
            if(__gcd(ans,i)==1) ans*=i,cnt--;
        }
        return ans;
    }
  public:
    long long maxGcd(int N) {
        // code here
        return max(helper(N),helper(N-1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends