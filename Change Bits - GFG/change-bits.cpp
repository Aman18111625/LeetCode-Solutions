// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        // int n=N,i=0,m=0;
        // while(n){
        //   if((1&n)==0){
        //       m|=(1<<i);
        //   }else{
        //       m|=(1<<i);
        //   }
        //   i++;
        //   n>>=1;
        // }
        // return {(m-N),m};
       int n = log2(N)+1;
       n = (1<<n)-1;
       return {abs(n-N),n};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends