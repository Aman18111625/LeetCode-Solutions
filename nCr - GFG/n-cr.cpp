// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        int m=1e9+7;
        //to optimize the value of r when it's large
        vector<vector<int>>dp(r+1,vector<int>(n+1,0));
        for(int i=0;i<=r;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || i==j)
                  dp[i][j]=1;
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=i;j<=n;j++){
                //j=i ->if r>n will return 0 which is already in dp
                dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%m;
            }
        }
        return dp[r][n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends