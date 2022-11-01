//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        //create graph
        vector<pair<int,int>>adj[N];
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dist(N,-1);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &it : adj[node]){
                int v=it.first;
                if(dist[v]==-1 or dist[node]+1<dist[v]){
                    dist[v]=dist[node]+1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends