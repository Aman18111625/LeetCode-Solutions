// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long karyTree(int k, int m) {
        // code here
        long long int  leaf=1;
        for(int i=0;i<m;i++){
            leaf=(leaf*k)%1000000007;
        }
        return leaf;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends