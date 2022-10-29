//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    // int helper(int i,int target,int sum,int n,int arr[],vector<vector<int>>&dp){
    //     if(i>=n or sum>target) return 0;
    //     if(target==sum) return 1;
    //     if(dp[i][sum]!=-1) return dp[i][sum];
    //     int op1=helper(i+1,target,sum+arr[i],n,arr,dp);
    //     int op2=helper(i+1,target,sum,n,arr,dp);
    //     return dp[i][sum]= op1 or op2;
    // }

    // int equalPartition(int N, int arr[])
    // {
    //     // code here
    //     int sum=0;
    //     for(int i=0;i<N;i++) sum+=arr[i];
    //     if(sum&1) return false;
    //     sum>>=1;
    //     vector<vector<int>>dp(N,vector<int>(sum,-1));
    //     return helper(0,sum,0,N,arr,dp);
    // }
    int equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for(int i = 0; i < N; i++){
            totalSum += arr[i];
        }
        if(totalSum & 1){
            return 0;
        }
        totalSum>>=1;
        vector<vector<bool>> dp(N + 1, vector<bool> (totalSum + 1, false));
        for(int i = 0; i <= N; i++){
            dp[i][0] = true;
        }
        for(int i = 1; i <= totalSum; i++){
            dp[0][i] = false;
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= totalSum; j++){
                dp[i][j] = dp[i - 1][j];
                if(j - arr[i - 1]  >= 0 && dp[i - 1][j - arr[i - 1]] == true){
                    dp[i][j] = true;
                }
            }
        }
        return dp[N][totalSum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends