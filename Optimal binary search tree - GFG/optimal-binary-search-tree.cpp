// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     int dp[101][101];
      int sumFreq(int i,int j,int freq[]){
          int sum=0;
          for(int k=i;k<=j;k++){
              sum+=freq[k];
          }
          return sum;
      }
      
      int optimalBST(int keys[],int freq[],int i,int j){
          if(i>j) return dp[i][j]=0;
          if(i==j) return dp[i][j]=freq[i];
          if(dp[i][j]!=-1) return dp[i][j];
          int sum=sumFreq(i,j,freq);
          int mini=INT_MAX;
          for(int k=i;k<=j;k++){
              int cost=optimalBST(keys,freq,i,k-1)+optimalBST(keys,freq,k+1,j);
              mini=min(mini,cost);
          }
          return dp[i][j]=mini+sum;
      }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return optimalBST(keys,freq,0,n-1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends