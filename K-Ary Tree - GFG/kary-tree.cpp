// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    //Time-Complexity:=> K*M
    // long long karyTree(int k, int m) {
    //     // code here
    //     long long int  leaf=1;
    //     for(int i=0;i<m;i++){
    //         leaf=(leaf*k)%1000000007;
    //     }
    //     return leaf;
    // }
    long long mod=1e9+7;
    long long recursive(int k,int m){
      long long temp;
      if(m==0) return 1;
      temp=recursive(k,m/2)%mod;
      if(m%2==0) return (temp*temp)%mod;
      return (k%mod* temp%mod* temp%mod)%mod;
    }
    long long karyTree(int k, int m){
       long long ans=0;
       ans=recursive(k,m)%mod;
       return ans;
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