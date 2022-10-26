//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<vector<int>>adj,vector<int>&vis,int V){
        vis[node]=true;
        for(int i=0;i<V;i++){
          if(adj[node][i] && !vis[i]){
              vis[i]=1;
              dfs(i,adj,vis,V);
          }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>vis(V,0);
        int ans=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis,V);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends