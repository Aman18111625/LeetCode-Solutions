// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
     int dfs(int s, int d, vector<vector<int>> &adj, vector<int>&vis){
        if(s==d) return 1;
        if(vis[s] != -1) return vis[s];
        int count = 0;
        for(auto it : adj[s]){
            count += dfs(it,d,adj,vis);
        }
        return vis[s]=count;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    //create-adjacency list of graph
	     vector<vector<int>>adj(n);
	    for(int i=0;i<edges.size();i++){
	        adj[edges[i][0]].push_back(edges[i][1]);
	    }
	    vector<int>vis(n,-1);//it's like a dp array which will store count of path till destination node from ith node
	    return dfs(s,d,adj,vis);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends