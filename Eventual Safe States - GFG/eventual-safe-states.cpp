//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool dfs(int src,vector<int>adj[],vector<int>&vis,vector<int>&pathVis,vector<int>&check){
        vis[src]=1;
        pathVis[src]=1;
    
        for(auto node: adj[src]){
            if(!vis[node]){
                if(dfs(node,adj,vis,pathVis,check)) {
                    check[node]=0;
                    return true;
                }
            }else if(pathVis[node]){
                check[node]=0;
                return true;
            }
        }
        check[src]=1;
        pathVis[src]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0),pathVis(V,0);
        vector<int>check(V,0),ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
              dfs(i,adj,vis,pathVis,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends