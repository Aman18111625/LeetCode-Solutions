// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int vis[100005];
    int dp[100005];
    int dfs(vector<vector<int>>&adj,int node){
        vis[node]=1;//mark node as visited 
        if(dp[node]!=-1) return dp[node];
        int ans=0;//node traverse for all the adjacent and find maximum color
        for(auto it : adj[node]){
            if(!vis[it]){//if not vis then call dfs
                ans=max(ans,dfs(adj,it));
            }else{
                ans=max(ans,dp[it]);//if already visited then take maximum of pre and curr
            }
        }
        return dp[node]=ans+1;
    }
    
    int minColour(int n, int m, vector<int> mat[]) {
        // code here
        //create adjacency matrix for directed graph
        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++){
            adj[mat[i][0]].push_back(mat[i][1]);
        }
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
         int maxi=0;
         //call dfs for every node and check
         for(int i=1;i<=n;i++){
             if(!vis[i]){
                  maxi=max(maxi,dfs(adj,i));
             }
         }
         return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends