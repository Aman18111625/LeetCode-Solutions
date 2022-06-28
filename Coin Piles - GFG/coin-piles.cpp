// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int N, int K) {
        // code here
        sort(A,A+N);
        vector<int>prefix(N+1,0);
        //prefix[i] stores sum till (i-1)th index
        for(int i=1; i<=N; i++){
            prefix[i] = prefix[i-1]+A[i-1];
        }
        int ans = INT_MAX;
        for(int i=0; i<N; i++){
            //ith element is minimum ele
            //means all coin piles left to that are removed
            int idx = upper_bound(A,A+N,A[i]+K)-A;
            // [idx,N-1] sum
            int greaterElementsSum = prefix[N]-prefix[idx];
            int reducedBy = (N-idx)*(A[i]+K);
            int coinsRemoved = greaterElementsSum-reducedBy;
            // for removed piles till i-1
            coinsRemoved += (prefix[i]);
            ans = min(ans,coinsRemoved);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends