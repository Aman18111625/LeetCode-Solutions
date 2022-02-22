// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
     int dp[101][101];
     //it'll give us sum from i to j
      int sumFreq(int i,int j,int freq[]){
          int sum=0;
          for(int k=i;k<=j;k++){
              sum+=freq[k];
          }
          return sum;
      }
      
      int optimalBST(int keys[],int freq[],int i,int j){
          //base case
          if(i>j) return dp[i][j]=0;
          if(i==j) return dp[i][j]=freq[i];
          //if already calculated
          if(dp[i][j]!=-1) return dp[i][j];
          int sum=sumFreq(i,j,freq);
          int mini=INT_MAX;
          //now check for every possible way
          for(int k=i;k<=j;k++){
              int left=optimalBST(keys,freq,i,k-1);//found cost to create left subtree
              int right=optimalBST(keys,freq,k+1,j);//found cost to create right subtree
              int cost=left+right;
              mini=min(mini,cost);//take mini of them
          }
          return dp[i][j]=mini+sum;//store into dp
      }
      //This is an MCM based problem 
      //DP on Trees
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