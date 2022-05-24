// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[1000001];
    bool solve(int ind,vector<int>&arr,int k,int m){
        int n=arr.size();
        if(ind>=n) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind+k-1;i<n;i++){
            int sub=abs(arr[i]-arr[ind]);
            if(sub>m) continue;
            bool next=solve(i+1,arr,k,m);
            if(next) return dp[ind]=true;
        }
        return dp[ind]=false;
    }
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
        sort(A.begin(),A.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,A,K,M);
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends