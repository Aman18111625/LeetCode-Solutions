// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int dp[201][201];
    int solve(int e,int f){
        //base condition
        if(e==1 || f==0 || f==1) return f;
        //already calculate
        if(dp[e][f]!=-1) return dp[e][f];
        int ans=INT_MAX;
        //now at every flow we have two option->1. egg will break 2. egg won't break
        for(int i=1;i<=f;i++){
            int temp=1+max(solve(e-1,i-1),solve(e,f-i));
            ans=min(ans,temp);
        }
        return dp[e][f]=ans;
    }
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends