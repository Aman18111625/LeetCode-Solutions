//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
    //create graph
      vector<pair<int,int>>adj[n+1];
      for(auto &e : edges){
          int u=e[0];
          int v=e[1];
          int wt=e[2];
          adj[u].push_back({v,wt});
          adj[v].push_back({u,wt});
      }
      
      vector<int>distance(n+1,INT_MAX); //to store distnace
      vector<int>parent(n+1);//to store parent node
      for(int i=0;i<=n;i++) parent[i]=i;
      //min heap to store pair of {dist,src}
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      pq.push({0,1});
      distance[1]=0;
      while(!pq.empty()){
         int dist=pq.top().first;
         int prev=pq.top().second;
         pq.pop();
         for(auto it:adj[prev]){
              int next_node=it.first;
              int next_dist=it.second;
              if(dist+next_dist<distance[next_node]){
                  distance[next_node]=dist+next_dist;
                  parent[next_node]=prev;
                  pq.push({distance[next_node],next_node});
              }
          }
      }
      if(distance[n]==INT_MAX) return {-1};
      vector<int>ans;
      int node=n;
      while(parent[node]!=node){
          ans.push_back(node);
          node=parent[node];
      }
      ans.push_back(1);
      reverse(ans.begin(),ans.end());
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends