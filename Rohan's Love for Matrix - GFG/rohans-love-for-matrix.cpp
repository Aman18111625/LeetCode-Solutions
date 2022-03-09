// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int firstElement(int n) 
    {
        // code here
        int a[n],b[n];
        a[0]=1,b[0]=1;
        for(int i=1;i<n;i++){
            b[i]=a[i-1];
            a[i]=(a[i-1]+b[i-1])%1000000007;
        }
        return b[n-1]%1000000007;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends