//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
using pii = pair<int,int>;
const int mod = 1e9+7;

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        //create graph
        vector<pii> adj[n];
        for(int i=0;i<roads.size();++i){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> distance(n,INT_MAX),ways(n,0);
        priority_queue<pii,vector<pii>,greater<pii>> pq; 
        pq.push({0,0});
        distance[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(dist+wt<distance[adjNode]){
                 distance[adjNode]=dist+wt;
                 pq.push({distance[adjNode],adjNode});
                 ways[adjNode]=ways[node];
                }else if(dist+wt==distance[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends