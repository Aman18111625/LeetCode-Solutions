// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // int solve(int A[],int N,int ind){
    //     if(ind>=N-1) return true;
    //     for(int i=1;i<=A[ind];i++){
    //         if(solve(A,N,ind+i)) return true;
    //     }
    //     return false;
    // }
   
    // int canReach(int A[], int N) {
    //     // code here
    //   return solve(A,N,0);
    // }
    
    int canReach(int A[], int N) {
       int maxi=A[0];
       for(int i=1;i<N;i++){
           if(i<=maxi){
               maxi=max(maxi,i+A[i]);
           }
       }
       return maxi>=N-1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends