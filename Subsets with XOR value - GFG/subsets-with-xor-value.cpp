// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
     int solve(vector<int>&arr,int ind, int k,int curr,vector<vector<int>>&dp){
         if(ind==0) return curr==k;
         if(dp[ind][curr]!=-1) return dp[ind][curr];
         int take=solve(arr,ind-1,k,curr^arr[ind-1],dp);
         int notTake=solve(arr,ind-1,k,curr,dp);
         return dp[ind][curr]=take+notTake;
     }
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(201,-1));
        return solve(arr,N,K,0,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends